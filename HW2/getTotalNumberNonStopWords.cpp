#include <iostream>
#include <string>
using namespace std;
#include <fstream>

int getTotalNumberNonStopWords(wordItem uniqueWords[], int length){
    int count = 0;
    for(int i = 0; i<length; i++){
            count += uniqueWords[i].count;
    }

    return count;
}