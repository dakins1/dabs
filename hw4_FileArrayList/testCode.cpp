#include <iostream>
using namespace std;
#include "FileArrayList.h"

int main() {
    //testing opening
    FileArrayList<int> testOpen("myFile.txt");
    if (testOpen.size() != 0) cout << "initializer test failed\n";
    //push_back
    for (int i=0; i!=10; i++) {
        testOpen.push_back(i);
        //if (testOpen[i] != i) cout << "push_back test failed at " << i << endl;
    }
}
