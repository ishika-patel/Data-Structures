#include <iostream>
using namespace std;

void swap_by_pointers(int *n1, int *n2) {
  int temp = *n1;
  *n1 = *n2;
 *n2 = temp;
  // TODO Complete this function
}

int main() {
int foo[5] = {1, 2, 3, 4, 5};

  cout << "Addresses of elements:" << endl;
  //TODO Print the addresses of array elements
  for (int i=0; i < 5; i++){
    cout << "Element " << i << ": " << foo+i<< endl;
  }

  cout << endl;

cout << "Elements:" << endl;
  //TODO Print all the elements using pointers
  for (int i=0; i < 5; i++){
    cout << "Element " << i << ": " << *foo+i<< endl;
  }

  swap_by_pointers(1, 2);
}