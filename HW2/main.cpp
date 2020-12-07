#include <iostream>
#include <string>
#include <iomanip> 
#include <fstream>
using namespace std;

/*
Your program must take three command line arguments in the following order - 
a number ​N,​ the name of the text to be read, and the name of the text file with the words that should be ignored.
 It will read the text (​ignoring the words in the second file)​ and store all unique words in a dynamically doubling array  
*/

struct wordItem {
    string word;
    int count;
};

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

int getTotalNumberNonStopWords(wordItem uniqueWords[], int length){
    int count = 0;
    for(int i = 0; i<length; i++){
            count += uniqueWords[i].count;
    }

    return count;
}

void arraySort(wordItem uniqueWords[], int length) {
        for (int i = 0; i < length; i++) {
        for (int j = i+1; j< length+1; j++){
            if (uniqueWords[j].count> uniqueWords[i].count){
               //basic array swap procedure
                float temp = uniqueWords[i].count;
                uniqueWords[i].count = uniqueWords[j].count;
                uniqueWords[j].count = temp;

                string tempName = uniqueWords[i].word;
                uniqueWords[i].word = uniqueWords[j].word;
                uniqueWords[j].word = tempName;
            }
        }
    }
}

void printNext10(wordItem uniqueWords[], int startRank, int totalNumWords) {
    for (int i = startRank; i < startRank + 10; i++){
        float prob = (float) uniqueWords[i].count/totalNumWords;
        cout << fixed << setprecision(4) << prob << " - " << uniqueWords[i].word << endl;
    }
}

int main(int argc, char* argv[]) {
    if(argc != 4){
        cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfileName.txt>" << endl;
    }
    else {
        string ignoreWords[50];
        getStopWords(argv[3], ignoreWords);

        int capacity = 100;
        wordItem *uniqueWords = new wordItem[capacity];
        wordItem *tempArray = nullptr;
        int wordCount = 1;
        int numberDoubled = 0;
        
        string word;
        ifstream infile;
        infile.open(argv[2]);

        if(infile.fail()){
            cout << "Failed to open the file." << endl;
        }
        else {
            while(infile >> word ){
                bool check = false;
                if (isStopWord(word, ignoreWords) == false) {
                    for (int i = 0; i < wordCount; i++) {
                        if (word == uniqueWords[i].word && !check) 
                        {
                            uniqueWords[i].count++;
                            check = true;
                        }
                        else if (i == wordCount - 1 && !check)
                        {
                            uniqueWords[wordCount].word = word;
                            uniqueWords[wordCount].count = 1;
                            wordCount++;
                            check = true;
                            i++;
                        }
                    }
                    if (capacity == wordCount) 
                    {
                    //Increase the capacity by two times
                    capacity = capacity * 2;

                    //Dynamically allocate an array of size capacity

                    tempArray = uniqueWords;

                    uniqueWords = new wordItem[capacity];

                    //Copy all data from oldArray to newArray
                    for(int i=0; i< capacity/2; i++) {
                        uniqueWords[i] = tempArray[i];
                    }

                    // TODO free the memory associated with oldArray
                    delete [] tempArray;
                    numberDoubled++;
                    }
            }
            }
cout << "Array doubled: " << numberDoubled << endl;
cout << "#" << endl;
cout << "Unique non-common words: " << wordCount -1 << endl;
cout << "#" << endl;
int total = getTotalNumberNonStopWords(uniqueWords, wordCount);
cout << "Total non-common words: " << total << endl;
cout << "#" << endl;
arraySort(uniqueWords, capacity);
cout << "Probability of next 10 words from rank " << argv[1] << endl;
cout << "---------------------------------------" << endl;
    printNext10(uniqueWords, stoi(argv[1]), total);

        }   
    }
}