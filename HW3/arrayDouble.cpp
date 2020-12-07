#include <iostream>
using namespace std;

bool append(string* &str_arr, string s, int &numEntries, int &arraySize){
    bool check = false;
    string *tempArray = NULL;
    int numberDoubled = 0;

    if(numEntries == arraySize) {
        //Increase the capacity by two times
        arraySize = arraySize *2;
        //Dynamically allocate an array of size capacity
        tempArray = str_arr;
        str_arr = new string[arraySize];
        //Copy all data from oldArray to newArray
        for(int i=0; i< arraySize/2; i++) {
            str_arr[i] = tempArray[i];
        }
        // Free the memory associated with oldArray
        delete [] tempArray;
        numberDoubled++;

        str_arr[numEntries] = s;
        numEntries++;
        check = true;
    }
    else {
    str_arr[numEntries] = s;
    numEntries++;
    }

    return check;
}