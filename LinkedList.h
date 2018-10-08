template <typename T>

class LinkedList {
    struct Node {
        T element;
        Node* prev;
        Node* next;
    };
    private:
        Node* sentinel;
        int sz;

    public:
        typedef T value_type;

        class iterator {
            private:
                Node* pointer; 

            public:
                iterator() { pointer = &sentinel; } //constructor
                iterator(Node* l) { pointer = l; } //constructor
                iterator(const iterator &i) { pointer = i.pointer; } //copy

                iterator& operator=(const iterator &i) { 
                    pointer = i.pointer; 
                    return *this;
                }

                T& operator*() { return pointer->element; }

                iterator& operator++() {
                    pointer = pointer->next;
                    return *this;
                } 

                iterator& operator++(int) {
                    pointer = pointer->next;
                    return *this;
                }  

                iterator& operator--(int) {
                    pointer = pointer->prev;
                    return *this;
                } 

                iterator& operator--() {
                    pointer = pointer->prev;
                    return *this;
                }

                bool operator==(const iterator &i) const { return (pointer == i.pointer); }
                bool operator!=(const iterator &i) const { return (pointer != i.pointer); }

                friend class LinkedList;
                friend class const_iterator;
        };

        class const_iterator {
            private: Node* pointer;

            public:
                const_iterator(Node* l) { pointer = l; }
                const_iterator() { pointer = &sentinel; }
                const_iterator(const const_iterator &i) { pointer = i.pointer; }
                bool operator==(const const_iterator &i) const { return (pointer == i.pointer); }
                bool operator!=(const const_iterator &i) const { return (pointer != i.pointer); }
                const_iterator& operator=(const const_iterator &i) {
                    pointer = i.pointer;
                    return *this;
                }
                
                const_iterator& operator++() {
                    pointer = pointer->next;
                    return *this;
                } 

                const_iterator& operator++(int) {
                    pointer = pointer->next;
                    return *this;
                }  

                const_iterator& operator--(int) {
                    pointer = pointer->prev;
                    return *this;
                } 

                const_iterator& operator--() {
                    pointer = pointer->prev;
                    return *this;
                }
            
                const T& operator*() { return pointer->element; }
        };

        LinkedList() {
            sentinel = new Node;
            sentinel->next = sentinel; //shouldn't this be &sentinel since -> is a pointer?:
            sentinel->prev = sentinel;
            sz = 0;
        }

        LinkedList &operator=(const LinkedList &lh) {
            clear();
            for (auto x : lh) push_back(x);
            sz = lh.sz;
            return *this; 
        }
        
        LinkedList(const LinkedList &al) : LinkedList() {
            for (auto x : al) push_back(x);
            sz = al.sz;
        }
        
/*
        void push_back(const T &t) {
            Node* newNode = new Node;
            newNode->element = t;
            newNode->next = sentinel;
            newNode->prev = sentinel->prev;
            sentinel->prev->next = newNode;
            sentinel->prev = newNode;
            sz++;
            if (sz == 1) sentinel->next = newNode;
        }  
*/

        iterator insert(iterator position, const T &t) {
            Node* newNode = new Node;
            newNode->element = t;
            newNode->next = position.pointer;
            newNode->prev = position.pointer->prev;
            position.pointer->prev->next = newNode;
            position.pointer->prev = newNode;
            sz++;
        }
        

        iterator erase(iterator position) {
            position.pointer->prev->next = position.pointer->next;            
            position.pointer->next->prev = position.pointer->prev;            
            sz--;
            auto temp = position.pointer->next;
            delete position.pointer;
            return temp;
        }

        void clear() {
            int n = size();
            for (int i=0; i<n; i++) pop_back();
        }

        void push_back(const T &t) {
            insert(end(), t);
        }

        void pop_back() {
            //arrange all the pointers
            //delete the actual element
            //adjust size
            sentinel->prev = sentinel->prev->prev;
            delete sentinel->prev->next;
            sentinel->prev->next = sentinel;
            sz--;
        }

        int size() { return sz; }
    
        const T& operator[](int index) const {
            auto iter = begin();
            for (int i=0; i!=index; i++) iter++;
            return iter.pointer->element;
        }

        T& operator[](int index) { 
            auto iter = begin();
            for (int i=0; i!=index; i++) iter++;
            return iter.pointer->element;
        }



        iterator begin() { return iterator(sentinel->next); }
        iterator end() { return iterator(sentinel); }        

        const_iterator begin() const { return const_iterator(sentinel->next); }
        const_iterator end() const { return const_iterator(sentinel); }

        const_iterator cbegin() const { return const_iterator(sentinel->next); }
        const_iterator cend() const { return const_iterator(sentinel); } 

        ~LinkedList() { while (sz > 0) pop_back(); }
};
