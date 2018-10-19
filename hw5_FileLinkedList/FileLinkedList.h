
template <typename T>
class FileLinkedList {

    struct Node {
        T data;
        int next;
        int prev;
    };

    private:
    FILE * f;
    int sz;

    public:
        typedef T value_type;

        //Constructors and what not
        FileLinkedList(const FileLinkedList<T> &that) = delete;
        FileLinkedList<T> operator=(const FileLinkedList<T> &that) = delete;
        FileLinkedList(const std::string &fname) { //constructor TODO
            f = fopen(fname.c_str(), "r+");
            if (f == nullptr) {
                f = fopen(fname.c_str(), "w+");
                //start with sentinel at 0
                fseek(f, sizeof(T), SEEK_SET);  
                int prev=0;
                fwrite(&prev, sizeof(int), 1, f);
                int next=0;
                fwrite(&next, sizeof(int), 1, f);
                //freelist
                int freelist=-1; 
                fwrite(&freelist, sizeof(int), 1, f);
                //sz
                sz = 0;
                fwrite(&sz, sizeof(int), 1, f);
            } else {
                //read in the size
                fseek(f, sizeof(Node)+sizeof(int), SEEK_SET);
                fread(&sz, sizeof(int), 1, f);
            }
        }

        //Helper functions
         static int ReadPrev(int node, FILE* file) {
            fseek(file,node+sizeof(T) , SEEK_SET);
                //moving to a small location 
                //inside the node
            int temp;
            fread(&temp, sizeof(int), 1, file );
                //this reads an address
            return temp;
        }

         static int WritePrev(int node, int value, FILE* file) {
            //essentially do the same thing as in ReadPrev,
            //but use fwrite
        }

         static int ReadNext(int node, FILE* file) {
            fseek(file, node+sizeof(T)+sizeof(int), SEEK_SET);
            int temp;
            fread(&temp, sizeof(int), 1, file );
                //this reads an address
            return temp;

        }

         static int ReadData(int node, FILE* file) {
            fseek(file, node, SEEK_SET);
            T temp;
            fread(&temp, sizeof(T), 1, file);
            return temp;
        }

         static void WriteNext(int address, int input, FILE * f) {
            fseek(f, address+sizeof(T)+sizeof(int), SEEK_SET);
            fwrite(&input, sizeof(int), 1, f);
        }
         static void WriteData(int address, T input, FILE * f) {
            fseek(f, address, SEEK_SET);
            fwrite(&input, sizeof(T), 1, f);
        }

            //make sure you're always reading from the right type,
            //the compile will not tell you if you're wrong

        //node allocation and deallocation helper funcs

        static int AllocateNode(FILE* file, int sz) { 
            int freeList;
            fseek(file, sizeof(Node) , SEEK_SET);
            fread(&freeList, sizeof(int), 1, file);
            int temp;
            if (freeList!=-1) /*-1 meaning empty*/ {
                temp = freeList; 
                freeList = ReadNext(freeList, file);
                fseek(file, sizeof(Node), SEEK_SET); //skips over the Sentinel
                fread(&freeList, sizeof(int), 1, file); //reads in the new freelist
            } else { //if free list is empty
                temp = sizeof(Node) + 2*sizeof(int) + sz*sizeof(Node); 
           }

            return temp;
        }
        
        void WriteSz() {
            fseek(f, sizeof(Node)+sizeof(int), SEEK_SET);
            fwrite(&sz, sizeof(int), 1, f);
        }
                
        void DeallocateNode(int node, FILE* file){
            //read freelist
            fseek(file, sizeof(Node), SEEK_SET); //skip over the sentinel
            int freelist;
            fread(&freelist, sizeof(int), 1, file); //read the address freelist gives
                //std::cout << "Freelist: " << freelist << endl;

            WriteNext(node, freelist, file); //node.next = freelist
            freelist=node; //free list is now the node that just got deleted
                //std::cout << "Freelist: " << freelist << endl;
            fseek(file, sizeof(Node), SEEK_SET);
            fwrite(&freelist, sizeof(int), 1, file); //update the freelist
        }        
        //const_iterator
        class const_iterator {
            private:
                FILE * f;
                int address;    
            public:
                const_iterator(int i, FILE * fIn) {
                    f = fIn;
                    address = i;  
                }
                const_iterator(const const_iterator &i) {
                    f = i.f;
                    address = i.address;
                }
                T operator*() { 
                    T temp;
                    fseek(f, address, SEEK_SET);
                    fread(&temp, sizeof(T), 1, f);
                    return temp;
                }
                const_iterator &operator=(const const_iterator &i) {
                    f = i.f;
                    address = i.address;
                    return this;
                }
                bool operator==(const const_iterator &i) { return address == i.address; }
                bool operator!=(const const_iterator &i) { return address != i.address; }
                const_iterator &operator++() {
                    address = ReadNext(address, f);
                    //std::cout << "Address after ++: " << address << '\n';
                    return *this;
                }
                const_iterator &operator--() {
                    address = ReadPrev(address, f);
                    //std::cout << "Address after --: " << address << '\n';
                    return *this;
                }
                const_iterator operator++(int) {
                    auto result = const_iterator(address, f);
                    address = ReadNext(address, f); 
                    //std::cout << "Address after ++: " << address << '\n';
                    return result;
                }
                const_iterator operator--(int) {
                    auto result = const_iterator(address, f);
                    address = ReadPrev(address, f); 
                    //std::cout << "Address after --: " << address << '\n';
                    return result;
                }
            
                friend class FileLinkedList;
                                
        };

        //General Methods
        int size() const { return sz; }
        void insert(const_iterator position, const T &t) {
            int newAddress = AllocateNode(f, sz);
            //link new node
            WriteData(newAddress, t, f);
            WriteNext(newAddress, position.address, f);
            WritePrev(newAddress, (position--).address, f);
            //relink preexisting nodes
            WriteNext((position--).address, newAddress, f);
            WritePrev(position.address, newAddress, f);
            sz++;
            WriteSz();
        }
        void push_back(const T &t) { insert(end(),t); }
        T operator[](int index) const {
            auto itr=begin();
            for (int i=0; i<index; ++i) ++itr;
            return *itr;
        }
        
        void printIter() {
            std::cout<< "begin -- : " << begin()--.address << '\n';
            std::cout << "end: " << end().address << '\n';
            std::cout << "end --: " << end()--.address << '\n';
            //std::cout << "Difend --: " << difEnd()--.address << '\n';
            //std::cout << "difend: " << difEnd().address << '\n';
        } 

        const_iterator begin() { return const_iterator(ReadNext(0, f), f); }
        //const_iterator end() { return const_iterator(0, f); }
        const_iterator end() { return begin()--; }
        const_iterator begin() const { return const_iterator(ReadNext(0, f), f); }
        const_iterator end()const { return begin()--; }
        //const_iterator end() const { return const_iterator(0, f); }

        ~FileLinkedList() { fclose(f); }
};

 
