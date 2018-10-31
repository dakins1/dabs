#include <cstdio>
#include <iostream>
using namespace std;
#include "FileLinkedList2.h"

struct Vect {
    int a;
};

int main() {
    FileLinkedList<int> test1("myTest.txt");
    test1.clear();
    for (int i=0; i!=10; i++) {
        test1.push_back(i); //fill the file
        if (i != test1[i]) cout << "push_back or [] failure; " << "i: " << i << " [i]: " << test1[i] << endl;
    }
    int count = 0;
    for (auto iter=test1.begin(); iter!=test1.end(); iter++) {
        test1.check_node(iter);
        if (*iter != count) cout << "iterator failure; *iter: " << *iter << " count: " << count << endl; 
        if (test1[count] != *iter) cout << "[] operator failure \n"; 
        count++; 
    } 
    int cnt = 9;
    for (auto iter=--test1.end(); iter!=test1.begin(); iter--) {
        test1.check_node(iter);
        if (*iter != cnt) cout << "backwards iterator failure *iter: " << *iter << " cnt: " << cnt << endl; 
        if (test1[cnt] != *iter) cout << "[] operator failure []: " << test1[cnt] << " iter: " << *iter << endl; 
        cnt--; 
    } 
    test1.insert(test1.begin(), 60);
    test1.insert(++++test1.begin(), 300);
    test1.insert(test1.end(), 400);
/*
    for (int i=0; i!=12; i++) {
        cout << i << ": " << test1[i] << '\n';
    }
//use to print out list elements
    for (auto iter=test1.begin(); iter!=test1.end(); iter++) {
        cout << *iter << '\n';
    }
*/
    if (test1[0] != 60) cout << "insert failure at 0, " << test1[0] << "\n";
    if (test1[1] != 0) cout << "insert failure at 1 " << test1[1] << "\n";
    if (test1[2] != 300) cout << "insert failure 2 " << test1[2] << "\n";
    if (test1[3] != 1) cout << "insert failure 3 " << test1[3] << "\n";
    if (test1[4] != 2) cout << "insert failure 4 " << test1[4] << "\n";
    if (test1[5] != 3) cout << "insert failure 5 " << test1[5] << "\n";
    if (test1[6] != 4) cout << "insert failure 6 " << test1[6] << "\n";
    if (test1[10] != 8) cout << "insert failure 10 " << test1[10] << "\n";
    if (test1[12] != 400) cout << "insert failure 12 " << test1[12] << "\n";

    test1.erase(test1.begin());
    if (*test1.begin() == 60) cout << "begin() erase failure \n";
    test1.erase(++test1.begin());
    if (*++test1.begin() == 300) cout << "++begin() erase failure \n";
    test1.erase(--test1.end());
    if (*--test1.end() == 400) cout << "--end() erase failure; *--end() =" << *--test1.end() << endl;

    count = 0;
    for (auto iter=test1.begin(); iter!=test1.end(); iter++) {
        test1.check_node(iter);
        if (*iter != count) cout << "post erase iterator failure; *iter: " << *iter << " count: " << count << endl; 
        if (test1[count] != *iter) cout << "post erase [] operator failure \n"; 
        count++; 
    } 
    cnt = 9;
    for (auto iter=--test1.end(); iter!=test1.begin(); iter--) {
        test1.check_node(iter);
        if (*iter != cnt) cout << "post erase backwards iterator failure *iter: " << *iter << " cnt: " << cnt << endl; 
        if (test1[cnt] != *iter) cout << "post erase [] operator failure []: " << test1[cnt] << " iter: " << *iter << endl; 
        cnt--; 
    } 
    test1.pop_back();
    if (*--test1.end() == 9) cout << "pop_back() failure \n";
    test1.pop_back();
    if (*--test1.end() == 8) cout << "pop_back() failure \n";
    test1.check_node(test1.end());

    //Clear
    test1.clear();
    if (test1.size() != 0) cout << "clear error \n";
    for (int i=0; i!=10; i++) {
        test1.push_back(i);
        if (test1[i] != i) cout << "push_back() error after clear \n";
    }
    count = 0;
    for (auto iter=test1.begin(); iter!=test1.end(); iter++) {
        if (*iter != count) cout << "iter error after clear \n";
        count++;
    }

    //Set
    test1.set(69, 5);
    if (test1[4] != 4) cout << "set error [4] == " << test1[4] << "\n";
    if (test1[5] != 69) cout << "set error [5] == " << test1[5] << "\n";
    if (test1[6] != 6) cout << "set error [6] == " << test1[6] << "\n";
    test1.set(420, ------test1.end());
    if (test1[6] != 6) cout << "set error [6] == " << test1[6] << "\n";
    if (test1[7] != 420) cout << "set error [7] == " << test1[7] << "\n";
    if (test1[8] != 8) cout << "set error [8] == " << test1[8] << "\n";

    /*
     *
     *
     ******Testing Double*****
     *
     *
     */

    FileLinkedList<double> test2("myTest2.txt");
    test2.clear();
    for (int i=0; i!=10; i++) {
        test2.push_back(i); //fill the file
        if (i != test2[i]) cout << "push_back or [] failure; " << "i: " << i << " [i]: " << test2[i] << endl;
    }
    count = 0;
    for (auto iter=test2.begin(); iter!=test2.end(); iter++) {
        test2.check_node(iter);
        if (*iter != count) cout << "iterator failure; *iter: " << *iter << " count: " << count << endl; 
        if (test2[count] != *iter) cout << "[] operator failure \n"; 
        count++; 
    } 
    cnt = 9;
    for (auto iter=--test2.end(); iter!=test2.begin(); iter--) {
        test2.check_node(iter);
        if (*iter != cnt) cout << "backwards iterator failure *iter: " << *iter << " cnt: " << cnt << endl; 
        if (test2[cnt] != *iter) cout << "[] operator failure []: " << test2[cnt] << " iter: " << *iter << endl; 
        cnt--; 
    } 
    test2.insert(test2.begin(), 60);
    test2.insert(++++test2.begin(), 300);
    test2.insert(test2.end(), 400);
/*
    for (int i=0; i!=12; i++) {
        cout << i << ": " << test2[i] << '\n';
    }
//use to print out list elements
    for (auto iter=test2.begin(); iter!=test2.end(); iter++) {
        cout << *iter << '\n';
    }
*/
    if (test2[0] != 60) cout << "insert failure at 0, " << test2[0] << "\n";
    if (test2[1] != 0) cout << "insert failure at 1 " << test2[1] << "\n";
    if (test2[2] != 300) cout << "insert failure 2 " << test2[2] << "\n";
    if (test2[3] != 1) cout << "insert failure 3 " << test2[3] << "\n";
    if (test2[4] != 2) cout << "insert failure 4 " << test2[4] << "\n";
    if (test2[5] != 3) cout << "insert failure 5 " << test2[5] << "\n";
    if (test2[6] != 4) cout << "insert failure 6 " << test2[6] << "\n";
    if (test2[10] != 8) cout << "insert failure 10 " << test2[10] << "\n";
    if (test2[12] != 400) cout << "insert failure 12 " << test2[12] << "\n";

    test2.erase(test2.begin());
    if (*test2.begin() == 60) cout << "begin() erase failure \n";
    test2.erase(++test2.begin());
    if (*++test2.begin() == 300) cout << "++begin() erase failure \n";
    test2.erase(--test2.end());
    if (*--test2.end() == 400) cout << "--end() erase failure; *--end() =" << *--test2.end() << endl;

    count = 0;
    for (auto iter=test2.begin(); iter!=test2.end(); iter++) {
        test2.check_node(iter);
        if (*iter != count) cout << "post erase iterator failure; *iter: " << *iter << " count: " << count << endl; 
        if (test2[count] != *iter) cout << "post erase [] operator failure \n"; 
        count++; 
    } 
    cnt = 9;
    for (auto iter=--test2.end(); iter!=test2.begin(); iter--) {
        test2.check_node(iter);
        if (*iter != cnt) cout << "post erase backwards iterator failure *iter: " << *iter << " cnt: " << cnt << endl; 
        if (test2[cnt] != *iter) cout << "post erase [] operator failure []: " << test2[cnt] << " iter: " << *iter << endl; 
        cnt--; 
    } 
    test2.pop_back();
    if (*--test2.end() == 9) cout << "pop_back() failure \n";
    test2.pop_back();
    if (*--test2.end() == 8) cout << "pop_back() failure \n";
    test2.check_node(test2.end());

    //Clear
    test2.clear();
    if (test2.size() != 0) cout << "clear error \n";
    for (int i=0; i!=10; i++) {
        test2.push_back(i);
        if (test2[i] != i) cout << "push_back() error after clear \n";
    }
    count = 0;
    for (auto iter=test2.begin(); iter!=test2.end(); iter++) {
        if (*iter != count) cout << "iter error after clear \n";
        count++;
    }

    //Set
    test2.set(69, 5);
    if (test2[4] != 4) cout << "set error [4] == " << test2[4] << "\n";
    if (test2[5] != 69) cout << "set error [5] == " << test2[5] << "\n";
    if (test2[6] != 6) cout << "set error [6] == " << test2[6] << "\n";
    test2.set(420, ------test2.end());
    if (test2[6] != 6) cout << "set error [6] == " << test2[6] << "\n";
    if (test2[7] != 420) cout << "set error [7] == " << test2[7] << "\n";
    if (test2[8] != 8) cout << "set error [8] == " << test2[8] << "\n";

    FileLinkedList<Vect> test3("myTest3.txt");
    test3.clear();
    for (int i=0; i!=1005; i++) {
        Vect in;
        in.a = i;
        test3.push_back(in);
    }
    int cunt = 0;
    for (auto iter=test3.begin(); iter!=test3.end(); iter++) {
        if (cunt != (*iter).a) cout << "struct error at " << cunt << "\n";
        if (test3[cunt].a != cunt) cout <<"struct [] error at " << cunt << endl;
        cunt++;
    }

    //for printing
    //for (int i=0; i!=10; i++) cout << test1[i] << endl;
    //for (auto iter=test1.begin(); iter!=test1.end(); iter++) cout << *iter << endl;
}
