#include <cstdio>
#include <iostream>
using namespace std;
#include "FileLinkedList.h"

int main() {
    FileLinkedList<int> test1("myTest.txt");
    for (int i=0; i!=20; i++) {
        test1.push_back(i); 
    }
    int count = 0;
    for (auto iter=test1.begin(); iter!=test1.end(); iter++) {
        test1.check_node(iter);
        if (*iter != count) cout << "iterator failure; *iter: " << *iter << " count: " << count << endl; 
        if (test1[count] != *iter) cout << "[] operator failure \n"; 
        count++; 
    }
    //cout << "Passed first iter and push_back() check\n";
    test1.clear();
    cout << "--cleared--\n";
    //test1.pop_back();
    test1.push_back(30);
    test1.push_back(31);
    test1.push_back(32);
    test1.push_back(33);
    test1.push_back(34);
    test1.clear();
    cout << "size after clear: " << test1.size() << endl;
    for (auto iter=test1.begin(); iter!=test1.end(); iter++) {
        cout << *iter << endl;
    }

    for (auto iter=test1.begin(); iter!=test1.end(); iter++) {
        test1.check_node(iter);
        if (*iter != count) cout << "iterator failure; *iter: " << *iter << " count: " << count << endl; 
        if (test1[count] != *iter) cout << "[] operator failure \n"; 
        count++; 
    }
    test1.erase(++++test1.begin());
    test1.pop_back();
    test1.erase(----test1.end());
    for (auto iter=test1.begin(); iter!=test1.end(); iter++) {
        int x = *iter; //just dummy filler
    }
    

}
