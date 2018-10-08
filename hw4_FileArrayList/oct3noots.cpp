

FileArrayList(const std::string &fname) {
    f = fopen(fname.c_str(), "r+");
    if (f!=nullptr) {
    }
    else {
        f=fopen(fname.c_str(), "w+");
        //initialize empty array or something
    }
}

//then you have a copy constructor that isn't really a copy constructor 

template<typename I> File ArrayList(I begin, I end, const std::string &fname)
   //you will pass a begin() and end() method/function into these 

        //open new file
        //empty array list
        for(auto iter=begin; iter!=end; iter++) {
            push_back(*i); //yuh
        }
//you could do a square bracket operator but that will take
//a LOT longer. So don't. 
//copy content from another contatiner using these iterators
//copy into current file
//basically what the copy constructor is doing
//you are passing a general container, as long as this container provides
//an iterator. You are passing a general object that has iterators
//so the type of iterator will be different, but iterators nontheless,
//so that's why you have the typename I or something
//having iterators allows you to write for loops without having to know
//unydung else
//I is an iterator of some sort

//you can write private helper functions that just kinda streamline the
//read/write process

//what you store in memory you should probably also save to the file

//what do we store in the file, and in what format?

//you have a pointer to the actual array/actual data
//no longer have to keep track of the capactiy
FILE* f; //allows us to access the file through fseek fread fwrite
//an array of bytes
T* arr;
int sz;

//store sz at the beginning so you know where the end is

T Read(int index) { //returns T NOT T&
    fseek(f,sizeof(int)+index*siezeof(T) ,SEEK_SET);
    T temp;
    fread(&temp , sizeof(T), f);
    return temp;
}
