#include <iostream>
using namespace std;

void reset(int *ip){
    ip =0;
}

int main() {
    int m =1;
    int n=2;
    int *pm = &m;
    int *pn=&n;
    int *r;
    r=pn;
    pn=pm;
    *pm = *pn+2;

    cout << m << " , " << n << ", " << *r << ", " << *pm << endl; 

    // int a[] = {1,3,5,7};
    // cout << *(a+2) << endl;

    // int i =100;
    // int *p = &i;
    // reset(p);
    // cout << *p << endl;
}