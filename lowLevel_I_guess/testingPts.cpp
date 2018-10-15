//dynamic memory allocation
#include <iostream>
using namespace std;

int main() {
    int t;
    t = 5;
    cout << t << endl;
    cout << &t << endl;
    int * u;
    *u = 6;
    cout << u << endl;
    cout << &u << endl;
    delete u;

}
