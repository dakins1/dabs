#include <utility>

template<typename T>
class ArrayList {
    private:
	T* data;
	int capacity;
	int sz;
	void growArray(){
		T* tmp = new T[capacity*4];
		for(int i=0;i<sz;++i)tmp[i]=data[i];
		delete[] data;
		data=tmp;
		capacity*=4;
	}
    public:
    // Types
        // value_type
	typedef T value_type;

        // iterator
	class iterator{

	  private:
		T* ptr;
	  public:
		
		iterator(T *l){
			ptr=l;
		}
                iterator(){
			ptr=nullptr;
		}
                iterator(const iterator &i){
			ptr=i.ptr;
		}
                T &operator*(){
			return *ptr;
		}
                bool operator==(const iterator &i) const{
			return ptr==i.ptr;
		}
                bool operator!=(const iterator &i) const{
			return ptr!=i.ptr;
		}
                iterator &operator=(const iterator &i){
			ptr=i.ptr;
			return *this;
		}
                iterator &operator++(){
			++ptr;
			return *this;
		}
                iterator &operator--(){
			--ptr;
			return *this;
		}
                iterator operator++(int){
			auto result = iterator(ptr);
			++ptr;
			return result;
		}
                iterator operator--(int){
			return ptr--;
		}



	};



        // const_iterator
	typedef const T* const_iterator;

        // General Methods
        ArrayList():data{new T[16]},capacity{16},sz{0} {}
        ArrayList(const ArrayList &that):data{new T[that.capacity]},capacity{that.capacity},sz{that.sz} 
	{
		for(int i=0;i<sz; ++i) data[i]=that.data[i];
	}
	ArrayList(ArrayList&& that):data{that.data},capacity{that.capacity},sz{that.sz}
	{
		that.data=nullptr;
		that.sz=0;
		that.capacity=0;
	}
        ArrayList<T> &operator=(const ArrayList<T> &al){
		ArrayList<T> tmp(al);
		std::swap(tmp.data,this->data);
		std::swap(tmp.capacity,this->capacity);
		std::swap(tmp.sz,this->sz);
		return *this;
	}
        
        ~ArrayList(){delete[] data;}
        void push_back(const T &t){           // add to the end.
		if(sz==capacity)growArray();
		data[sz]=t;
		++sz;
	}
        void pop_back(){if (sz>0) --sz;}                      // remove last element.
        int size() const{return sz;}
        void clear(){sz=0;}
        void insert(const T &t,int index){    
		// insert this element before the given index.
		if(sz==capacity)growArray();
		for(int i=size();i>index;--i)
			std::swap(data[i],data[i-1]);
		data[index]=t;
		++sz;
	}
        const T &operator[](int index) const{return data[index];} // get the element at index.
        T &operator[](int index){return data[index];}             // get the element at index.
        void remove(int index){               // remove the item at the given index.
		for(int i=index; i<size()-1; i++)
			std::swap(data[i],data[i+1]);
		sz--;
	}
        iterator begin(){
		return  iterator( data );
	}
        const_iterator begin() const{return &data[0];}
        iterator end(){
		return data+sz;
	}
        const_iterator end() const{return data+sz;}
        const_iterator cbegin() const{return &data[0];}
        const_iterator cend() const{return cbegin()+size(); }
};
