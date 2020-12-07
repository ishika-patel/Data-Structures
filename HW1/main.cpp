#include <iostream>
#include <fstream>
using namespace std;


int insertIntoSortedArray(float myArray[], int numEntries, float newValue){
    //adding in the new value to the end
    myArray[numEntries] = newValue;

    for (int i = 0; i < numEntries; i++) {
        for (int j = i+1; j< numEntries+1; j++){
            if (myArray[j]> myArray[i]){
               //basic array swap procedure
                float temp = myArray[i];
                myArray[i] = myArray[j];
                myArray[j] = temp;
            }
        }
    }
    //increment at the end once sorted becuase the new val is added
    numEntries = numEntries + 1;
    return numEntries;
}

int main(int argc,char* argv[]) {
    static float array[100];

    string line;

    ifstream infile;
    infile.open(argv[1]);

    if(infile.fail()){
        cout << "Failed to open the file." << endl;
    }
    else {
        int numSorted = 0;
        while(getline(infile,line)){
           insertIntoSortedArray(array, numSorted, stod(line));
            numSorted ++;
           for (int i = 0; i < numSorted; i++) {
               if (i == numSorted-1) {
                   cout << array[i];
               }
               else {
                   cout << array[i] << ",";
               }
           }
           cout << endl;
       } 
    }
}