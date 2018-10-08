#include <iostream>
using namespace std;
#include "LinkedList.h"

struct Vect {
    int x;
    int y;
};

int main() {
    
    //testing push_back(), size()
    LinkedList<int> testInt;
    for (int i=0; i!=10; i++) testInt.push_back(i);
    if (testInt.size() != 10) cout << "size() test failed \n";
    int cnt = 0;
    for (auto iter=testInt.begin(); iter!=testInt.end(); ++iter) {
        if (*iter != cnt) cout << "Push back and/or iterator test failed at " << cnt << endl;
        cnt++;
    }

    LinkedList<int> testIndex;
    for (int i=0; i!=10; i++) {
        testIndex.push_back(i);
        if (testInt[i] != i) cout << "[] operator failed at " << i << endl;
    }
    for (int i=9; i!=-1; i--) { 
        if (testIndex[i] != i) cout << "pop_back() test failed at " << i << endl;
        testIndex.pop_back(); 
    }
    
    //testing ++ operators
    LinkedList<int> testPlus; 
    for (int i=0; i!=10; i++) testPlus.push_back(i);
    cnt = 0;
    for (auto iter=testPlus.begin(); iter!=testPlus.end(); iter++) {
        if (*iter != cnt) cout << "iter++ test failed at " << cnt << endl;
        cnt++;
    }

    cnt = 0;
    for (auto iter=testPlus.begin(); iter!=testPlus.end(); ++iter) {
        if (*iter != cnt) cout << "iter++ test failed at " << cnt << endl;
        cnt++;
    }

    cnt = 9;
    for (auto iter=testPlus.end()--; iter!=testPlus.begin(); --iter) {
        //cout << "count: " << cnt << "iter " << *iter << endl;
        if (*iter != cnt) cout << "iter++ test failed at " << cnt << endl;
        cnt--;
    }

    cnt = 9;
    for (auto iter=testPlus.end()--; iter!=testPlus.begin(); iter--) {
        if (*iter != cnt) cout << "iter++ test failed at " << cnt << endl;
        cnt--;
    }

    //testing bool operators
    if (testPlus.begin() != testPlus.begin()) cout << "== operator failed \n";
    if (testPlus.end() == testPlus.begin()) cout << "!= operator failed \n";

    //testing erase()
    LinkedList<int> testErase;
    for (int i=0; i!=5; i++) {
        testErase.push_back(i);
    }
    testErase.erase(--(testErase.end()--));
    
    if (testErase[3] == 3) cout << "erase test 1 failed\n";
    if (testErase[3] != 4) cout << "erase test 2 failed\n";

    /***Test double****/

    //testing clear
    LinkedList<int> testClear;
    for (int i=0; i!=10; i++) testClear.push_back(i);
    testClear.clear();
    if (testClear.size() != 0) cout << "clear test failed \n";
    
    //test1ing push_back(), size()
    LinkedList<int> test1Int;
    for (int i=0; i!=10; i++) test1Int.push_back(i);
    if (test1Int.size() != 10) cout << "size() test1 failed \n";
     cnt = 0;
    for (auto iter=test1Int.begin(); iter!=test1Int.end(); ++iter) {
        if (*iter != cnt) cout << "Push back and/or iterator test1 failed at " << cnt << endl;
        cnt++;
    }


    LinkedList<double> test1Index;
    for (int i=0; i!=10; i++) {
        test1Index.push_back(i);
        if (test1Int[i] != i) cout << "[] operator failed at " << i << endl;
    }
    for (int i=9; i!=-1; i--) { 
        if (test1Index[i] != i) cout << "pop_back() test1 failed at " << i << endl;
        test1Index.pop_back(); 
    }
    
    //test1ing ++ operators
    LinkedList<int> test1Plus; 
    for (int i=0; i!=10; i++) test1Plus.push_back(i);
    cnt = 0;
    for (auto iter=test1Plus.begin(); iter!=test1Plus.end(); iter++) {
        if (*iter != cnt) cout << "iter++ test1 failed at " << cnt << endl;
        cnt++;
    }

    cnt = 0;
    for (auto iter=test1Plus.begin(); iter!=test1Plus.end(); ++iter) {
        if (*iter != cnt) cout << "iter++ test1 failed at " << cnt << endl;
        cnt++;
    }

    cnt = 9;
    for (auto iter=test1Plus.end()--; iter!=test1Plus.begin(); --iter) {
        //cout << "count: " << cnt << "iter " << *iter << endl;
        if (*iter != cnt) cout << "iter++ test1 failed at " << cnt << endl;
        cnt--;
    }

    cnt = 9;
    for (auto iter=test1Plus.end()--; iter!=test1Plus.begin(); iter--) {
        if (*iter != cnt) cout << "iter++ test1 failed at " << cnt << endl;
        cnt--;
    }

    //test1ing bool operators
    if (test1Plus.begin() != test1Plus.begin()) cout << "== operator failed \n";
    if (test1Plus.end() == test1Plus.begin()) cout << "!= operator failed \n";

    //test1ing erase()
    LinkedList<int> test1Erase;
    for (int i=0; i!=5; i++) {
        test1Erase.push_back(i);
    }
    test1Erase.erase(--(test1Erase.end()--));
    
    if (test1Erase[3] == 3) cout << "erase test1 1 failed\n";
    if (test1Erase[3] != 4) cout << "erase test1 2 failed\n";

    //test1ing clear
    LinkedList<int> test1Clear;
    for (int i=0; i!=10; i++) test1Clear.push_back(i);
    test1Clear.clear();
    if (test1Clear.size() != 0) cout << "clear test1 failed \n";

    /*********Testing Vect***********/

    LinkedList<Vect> test3;

    for (int i=0; i!=1005; i++) {
        Vect input;
        input.x = 1;
        input.y = 2;
        test3.push_back(input);
    }
}
