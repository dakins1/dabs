#include <iostream>
using namespace std;
#include "FileArrayList.h"

int main() {
    //testing opening
    FileArrayList<int> testOpen("myFile.txt");
    //if (testOpen.size() != 0) cout << "initializer test failed\n";
    //push_back

    for (int i=0; i!=10; i++) {
        testOpen.push_back(i);
        if (testOpen[i] != i) cout << "push_back test failed at " << i << endl;
    }
    if (testOpen[0] == testOpen.size()) cout << "something wrong with the sz\n";
    int initSz = testOpen.size();
    for (int i=0; i!=10; i++) { testOpen.pop_back(); }
        if (testOpen.size() != initSz-10) cout << "something wrong with pop_back\n"; 
    for (int i=0; i!=20; i++) { testOpen.push_back(i); }
    testOpen.clear();
    if (testOpen.size() != 0) cout << "clear test failed\n";
    for (int i=0; i!=20; i++) { 
            testOpen.push_back(i); 
            if (testOpen[i] != i) cout << "something went wrong after clear \n";
    }
    int count = 0;
    for (auto iter=testOpen.begin(); iter!= testOpen.end(); iter++) {
        if (*iter != count) cout << "iter test failed\n";
        if (*iter != testOpen[count]) cout << "iter fail\n";
        count++;
    }
    testOpen.insert(--(--(--(--(testOpen.end())))), 42);
    if (testOpen[testOpen.size()-4] != 42) cout << "something wrong with insert\n";
    count = 0;

    FileArrayList<int> testInsert("myFileTest.txt");
    for (int i=0; i!=20; i++) { testInsert.push_back(i); }
    testInsert.insert(++(testInsert.begin()++), 42);
    if (testInsert[2] != 42) cout << "something wrong with insert\n";

    if (testInsert.size() != 21) cout << "somethign wrong with size after insert\n";

    testInsert.erase(++(++(testInsert.begin()++)));
    if (testInsert[2] == 42) cout << "something wrong with erase\n";
    count =0;
    for (auto iter=testInsert.begin(); iter!= testInsert.end(); iter++) {
      if (*iter != count) cout << "erase failed\n";
      count++;
   } 
    
}
