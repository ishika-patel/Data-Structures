#include <iostream>
#include <fstream>

using namespace std;

int main() {
   int a[] = {5,4,3,2,1};
   int* ptr = (int*)(a+4);
   cout << *a+1 << ", " << *(ptr-1) << endl;
   
    // int x = 5;
    // int &y = x;
    // int *z = &y;

    // x = 20;
    // y = 15;
    // *z = 10l;

    // cout << x << ", " << y << endl;
}