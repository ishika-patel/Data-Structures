#include <iostream>
using namespace std;

void add2(int a[], int len){
    for (int i=0; i<len; i++){
        a[i]+= 2;
    }
}

int main() {
    int a[] = {1,2,3};
    // memory location of 3 in array
    // arrays automatically assign pointer to a
    cout << a+2 << endl;
    // memory location of 3 in array
    int *pointer = &a[2];
    cout << pointer << endl;
    //value at a[2] = 3
    cout << *(a+2) << endl;
    //value at a[0] = 1
    cout << *a << endl;
    // error?
    // dereferencing a thing that is no longer a pointer
    //cout << *a[0] << endl;


add2(a,3);

for (int i=0; i<3; i++) {
    cout <<a[i] << endl;
}
// ​for​ (int​ i=​0​;i< ​3;​ i++) {
//     ​cout​ << a[i] << ​endl​ ;
// }
}