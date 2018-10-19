#include <cstdio>
#include <iostream>
#include "FileLinkedList.h"
using namespace std;

int main() {
    FileLinkedList<int> test1("myTits.txt");
    for (int i=0; i!=10; i++) {
        test1.push_back(i);
    }
    int cunt = 0;
    for (auto iter=test1.begin(); iter!=test1.end(); iter++) {
        if (*iter != cunt) cout << "failure \n";
        cunt++; 
    } 
    cunt = 9;
    for (auto iter=test1.end(); iter!=test1.begin(); iter--) {
        if (*iter != cunt) cout << "failure \n";
        cunt--; 
    } 
    test1.insert(test1.begin(), 69);
    test1.push_back(70);
    test1.insert(test1.begin(), 69);
    for (int i =0; i!=10; i++) {
        cout << test1[i] << '\n';
    }
    for (auto iter=test1.begin(); iter!=test1.end(); iter++) {
        //cout << *iter << '\n';
    }
    if (test1[7] != 69) cout << "insert failure \n";
    if (test1[5] != 5) cout << "insert failure \n";
    if (test1[6] != 6) cout << "insert failure \n";
    if (test1[8] != 7) cout << "insert failure \n";
    if (test1[9] != 8) cout << "insert failure \n";
}
