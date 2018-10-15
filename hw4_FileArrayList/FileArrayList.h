template <typename T>
class FileArrayList {

    private:
        FILE* f;
        int sz; //array size, NOT FILE SIZE!
    public:
        typedef T value_type;
        //Helper functions
        T read(int fileIndex) const  {
            fseek(f, sizeof(int)+fileIndex*sizeof(T), SEEK_SET);
            T temp; //allocate memory to fill
            fread(&temp, sizeof(T), 1, f); 
            return temp;
        }

        void write(const T t, const int fileIndex) { //includes sz bytes
            fseek(f, sizeof(int)+fileIndex*sizeof(T), SEEK_SET);
            fwrite(&t, sizeof(T), 1, f);
        }

        void writeSz() { write(sz, 0); }
    class const_iterator {
        private:
            int arrayIndex;
            FILE* f;
        public:
            const_iterator(int in, FILE* fIn){
                arrayIndex = in;
                f = fIn;
		    }
            const_iterator(){
                arrayIndex = 0;
                f = nullptr;
		    }

            const_iterator(const const_iterator &i) {
                arrayIndex = i.arrayIndex;
                f = i.f;
		    }
            T operator*(){ //TODO slash need to review
			    fseek(f, sizeof(int)+arrayIndex*sizeof(T), SEEK_SET);
                T temp;
                fread(&temp, sizeof(T), 1, f);
                return temp; 
		    }
            bool operator==(const const_iterator &i) const{
                return ((arrayIndex == i.arrayIndex) && (f == i.f));
		    }
            bool operator!=(const const_iterator &i) const{
                return ((arrayIndex != i.arrayIndex) || (f != i.f));
		    }
            const_iterator &operator=(const const_iterator &i){
                arrayIndex = i.arrayIndex;
                f = i.f;
			    return *this;
		    }

            const_iterator &operator++(){
			    ++arrayIndex;
			    return *this;
		    }
    
            const_iterator &operator--(){
			    --arrayIndex;
			    return *this;
		    }
            const_iterator operator++(int){
			    auto result = const_iterator(arrayIndex, f);
			    ++arrayIndex;
			    return result;
		    }
            const_iterator operator--(int){
                auto result = const_iterator(arrayIndex, f);
			    --arrayIndex;
                return result;
		    }
            friend class FileArrayList;
	};
 
        //Constructors
        FileArrayList(const FileArrayList<T> &that) = delete;
        FileArrayList<T> operator=(const FileArrayList<T> &that) = delete;
        template<typename I>
        FileArrayList(I begin, I end, const std::string &fname) {
            f = fopen(fname.c_str(), "w+");
            sz = 0;
            writeSz();
            for (auto iter=begin; iter!=end; iter++) {
                push_back(*iter);
            }
        }

        FileArrayList(const std::string &fname) { 
            f = fopen(fname.c_str(), "r+");
            if (f == nullptr) {
                f = fopen(fname.c_str(), "w+");
                sz = 0;
                fseek(f, 0, SEEK_SET);
                fwrite(&sz, sizeof(int), 1, f); //puts array size of 0 at beginning
                //fread(&sz, sizeof(int), 1, f);
            } else {
                sz = read(0);
            }
        }

        //General Methods
        T operator[](int index) const {
            T temp;
            temp = read(index+1); 
            return temp;
        }

        int size() { return sz; };
    
        void push_back(const T& t) { 
            write(t, sz+1); 
            sz++;
            writeSz();
        }

        void pop_back() { 
           // T temp;
           //temp = read(sz);
            if (sz>0) {
                sz--;
                writeSz();
            }
        }

        void clear() { 
            sz = 0;
            writeSz();
        }

        const_iterator insert(const_iterator position, const T &t) {
            for (auto iter=end(); iter!=position; iter--) {
                write(*iter, iter.arrayIndex+1);
            }        
            write(t, position.arrayIndex+1);
            sz++;
            writeSz(); 
        }

        const_iterator erase(const_iterator position) {
            for (auto iter=position; iter!=end(); iter++) {
                auto nextElem = iter;
                nextElem++;
                write(*nextElem, iter.arrayIndex);
            }
            sz--;
            writeSz();
        }

        void set(const T& value, int index) {
            const_iterator iter(index, f);
        } 

        const_iterator begin() { return const_iterator(1, f);  }
        const_iterator end() { return const_iterator(sz+1,f);  }
        const_iterator begin() const { return const_iterator(1, f);  }
        const_iterator end() const { return const_iterator(sz+1,f);  }
        const_iterator cbegin() const { return const_iterator(1, f);  }
        const_iterator cend() const { return const_iterator(sz+1,f);  }

                
        
    ~FileArrayList() { fclose(f); }
            
};
