#include <iostream>
#include <string>
using namespace std;
#include <fstream>

bool isStopWord(string word, string ignoreWords[]){

    bool check = false;
    for (int i = 0;  i< 50; i++){
            if (ignoreWords[i] == word) {
                check = true;
            }
            else {
                check = check;
            }
    }
    return check;
    
}