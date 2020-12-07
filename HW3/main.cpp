/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "CountryNetwork.hpp"
#include <iostream>
#include <fstream>                                                                                                                                                                                             

void displayMenu();  // declaration for main's helper-function

int main(int argc, char* argv[])
{
    // Object representing our network of cities.
    // (Linked list representation is in CountryNetwork)
    CountryNetwork CountryNet;
    string userInput;
    bool check = true;

    while(check == true){
        displayMenu();
        getline(cin,userInput);

        if (stoi(userInput) == 1) {
        CountryNet.loadDefaultSetup();
        CountryNet.printPath();
        }
        if (stoi(userInput) == 2) {
        CountryNet.printPath();
        }
        if (stoi(userInput) == 3) {
            string userCountry;
            string userMessage;
            cout<< "Enter name of the country to receive the message:" << endl;
            getline(cin,userCountry);
            cout <<"Enter the message to send:" << endl;
            getline(cin,userMessage);
            cout << endl;

            CountryNet.transmitMsg(userCountry, userMessage);
        }
        if (stoi(userInput) == 4) {     
            string newCountry;
            string previous;
            cout<< "Enter a new country name:" << endl;
            getline(cin,newCountry);
            cout <<"Enter the previous country name (or First):" << endl;
            getline(cin,previous);

            if (CountryNet.searchNetwork(previous) == NULL) {
                if(previous == "First")
                {
                    goto continueToNext;

                }
                cout << "INVALID(previous country name)...Please enter a VALID previous country name!" << endl;
                getline(cin,previous);
            }
           continueToNext:
                CountryNet.insertCountry(CountryNet.searchNetwork(previous), newCountry);
                CountryNet.printPath();
            
        }
        if (stoi(userInput) == 5) {
            cout << "Quitting..."<< endl;
            cout << "Goodbye!" << endl;
            check = false;
        }
    }

    return 0;
}


/*
 * Purpose; displays a menu with options
 */
void displayMenu()
{
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Transmit Message " << endl;
    cout << " 4. Add Country " << endl;
    cout << " 5. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}

       /* if (stoi(userInput) == 4) {
            string newCountry;
            string previous;
            cout<< "Enter a new country name:" << endl;
            getline(cin,newCountry);
            cout <<"Enter the previous country name (or First):" << endl;
            getline(cin,previous);

            if (CountryNet.searchNetwork(previous) == NULL) {
                cout << "INVALID(previous country name)...Please enter a VALID previous country name!" << endl;
                getline(cin,previous);
            }
            if(previous == "First"){
                CountryNet.insertCountry(NULL, newCountry);
                CountryNet.printPath();
            }
            else {
                CountryNet.insertCountry(CountryNet.searchNetwork(previous), newCountry);
                CountryNet.printPath();
            }
        }
        */