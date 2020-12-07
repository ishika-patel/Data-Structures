#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <math.h>
using namespace std;

int split(string line, char delimiter, string array[], int arraySize){
    
    int count =0; // this allows us to return the counter
    int start =0; // this will track where in the string we are as we are looking for the delimiter
    
    if (line == "") { //checks to see if the parameter for string is empty
        return 0; //if it is, returns 0 and exits code
    }
    if (line[line.length()-1] == delimiter) { //checks to see if the last value in the string is the delimiter
        line = line.substr(0, line.length()-1); // if it is, the delimiter at the end is cut off and the process is continued
    }
    
    for (int i = 0; i<line.length(); i++) {
        if (line[i] == delimiter) { // we are now searching for the delimiter
            
            if (count == arraySize) { // this is a fail safe to make sure that the count is not greater than the value that the array can hold
                return -1; //If the string is split into more pieces than the array of string can hold return -1
            }
            else {
                string arrayInput = line.substr(start, i-start); // int i is where the delimiter was found, thefore we want to print the strin from the beinning to int i
                if (i-start !=0 && start+1 !=0) { // the first condition checks to make sure two delimiters are together, the second condition checks the starting position
                    array[count] = arrayInput;  // store the value that is extrapolated from arrayInput
                    count ++; // add one to the count to return the number of words at the end, note that count doesnt include the very final word
                }
                }
            start = i + 1; // becuase you are moving past the whole word so you have to move up to i where the delimiator was and 1 past i so you pass the delimiter
            }
         }
         
         string arrayInput = line.substr(start, line.length() - start); 
             if (arrayInput != "") {// keeps the process going until the string itself ends
                 array[count] = arrayInput;
             }
         return ++count; //preincrement in order to account for index vs length discrepecy
         }

struct Park {
    string parkname;
    string state;
    int area;
};

void addPark(Park parks[], string parkname, string state, int area, int length) {
    Park parkInput = {parkname, state, area};
    parks[length] = parkInput;
}

void printList(const Park parks[], int length) {
    for (int i = 0; i < length; i++) {
        cout << parks[i].parkname << " [" << parks[i].state << "] area: " << parks[i].area << endl;
    }
}

int main(int argc,char* argv[]){
    ifstream infile;
    infile.open(argv[1]);
    int numSorted = 0;
    Park parks[100];

    if(infile.fail()){
        cout << "Failed to open the file." << endl;
    }
    else {
        string line;
        while(getline(infile,line)){
            string tempArray[3];
            string tempName;
            string tempState;
            int tempArea;
            split(line,',', tempArray,3);
            tempName = tempArray[0];
            tempState = tempArray[1];
            tempArea = stoi(tempArray[2]);
            addPark(parks,tempName, tempState, tempArea,numSorted);
            numSorted++;           
    }
}
printList(parks,numSorted);

ofstream outfile;
outfile.open(argv[2]);
for (int i=0; i< numSorted; i++){
    if (parks[i].area >= stoi(argv[3]) && parks[i].area <= stoi(argv[4])){
        outfile << parks[i].parkname << ","<< parks[i].state <<","<< parks[i].area << endl;
    }
}

}