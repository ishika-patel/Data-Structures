#include <iostream>
#include <string>
using namespace std;
#include <fstream>

void getStopWords(const char *ignoreWordFileName, string ignoreWords[]){

    ifstream infile;
    infile.open(ignoreWordFileName);

    if(infile.fail()){
        cout << "Failed to open " << ignoreWordFileName << endl;
    }
    else {
        string line;
        int i = 0;
        while(getline(infile,line)){
            ignoreWords[i] = line;
            i++;
        }
    }
}