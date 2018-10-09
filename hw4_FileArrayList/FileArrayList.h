
template <typename T>
class FileArrayList {

    private:
        FILE* f;
        int sz;
    public:
        //Helper functions
        T read(int index) {
            fseek(f, sizeof(int)+index*sizeof(T), SEEK_SET);
            T temp; //allocate memory to fill
            fread(&temp, sizeof(T), 1, f); 
            return temp;
        }

        void write(T& t, int index) { 
            fseek(f, sizeof(int)+index*sizeof(T), SEEK_SET);
            fwrite(&t, sizeof(T), 1, f);
        }

        FileArrayList(const std::string &fname) { 
            f = fopen(fname.c_str(), "r+");
            if (f == nullptr) {
                f = fopen(fname.c_str(), "w+");
                fseek(f, 0, SEEK_SET);
                sz = 0;
                fwrite(&sz, sizeof(int), 1, f); //puts array size of 0 at beginning
                //fread(&sz, sizeof(int), 1, f);
            } else {
                sz = read(0);
            }
        }

        T operator[](int index) const {

template <typename T>
class FileArrayList {

    private:
        FILE* f;
        int sz;
    public:
        //Helper functions
        T read(int index) {
            fseek(f, sizeof(int)+index*sizeof(T), SEEK_SET);
            T temp; //allocate memory to fill
            fread(&temp, sizeof(T), 1, f); 
            return temp;
        }

        void write(T& t, int index) { 
            fseek(f, sizeof(int)+index*sizeof(T), SEEK_SET);
            fwrite(&t, sizeof(T), 1, f);
        }

        FileArrayList(const std::string &fname) { 
            f = fopen(fname.c_str(), "r+");
            if (f == nullptr) {
                f = fopen(fname.c_str(), "w+");
                fseek(f, 0, SEEK_SET);
                sz = 0;
                fwrite(&sz, sizeof(int), 1, f); //puts array size of 0 at beginning
                //fread(&sz, sizeof(int), 1, f);
            } else {
                sz = read(0);
            }
        }

        T operator[](int index) const {
           return read(index); 
        }

        int size() { return sz; };
    
        void push_back(T& t) { write(t, sz+1); }

                
        
    ~FileArrayList() { fclose(f); }
            
};
           return read(index); 
        }

        int size() { return sz; };
    
        void push_back(T& t) { write(t, sz+1); }

                
        
    ~FileArrayList() { fclose(f); }
            
};
