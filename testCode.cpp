#include <iostream>
using namespace std;
#include "LinkedList.h"

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

}
