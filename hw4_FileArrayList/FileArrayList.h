//good lordy I am so fucked! AFJAIWEJFIA!!!!

template <typename T>
class FileArrayList {

    private:
        FILE* f;
    public:
        FileArrayList(const std::string &fname) { 
            f = fopen(fname.c_str(), "r+");
            if (f == nullptr) {
                f= fopen(fname.c_str(), "w+");
                fseek(f, 0, SEEK_SET);
                fwrite(0, sizeof(int), 1, f); //puts array size of 0 at beginning
            }
        }

        T read(int index) {
            fseek(f, sizeof(int)+index*sizeof(T), SEEK_SET);
            T temp; //allocate memory to fill
            fread(&temp, sizeof(T), /*count??*/ f); 
            return temp;
        }
        
        void write(T& t, int index) { 
            fseek(f, sizeof(int)+index*sizeof(T), SEEK_SET);
            fwrite(t, sizeof(T), 1, f);
        }

    ~FileArrayList() { fclose(f); }
            
};
