/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork()
{
    head = NULL;

}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */

// REFERENCED AND MODIFIED RECITATION 4 INSERT FUCTION WHICH WAS PROVIDED
void CountryNetwork::insertCountry(Country* previous, string countryName)
{
//Check if head is Null i.e list is empty
if(head == NULL){
    head = new Country;
    head->name = countryName;
    head->next = NULL;
    cout << "adding: " << countryName << " (HEAD)"<< endl;
}

// if list is not empty, look for prev and append our node there
else if(previous == NULL)
{
    Country* newCountry = new Country;
    newCountry->name = countryName;
    newCountry->next = head;
    head = newCountry;
    cout << "adding: " << countryName << " (HEAD)"<< endl;
}

else{

    Country* newCountry = new Country;
      newCountry->name = countryName;
      newCountry->next = previous->next;
      previous->next = newCountry;
      cout<< "adding: " << countryName << " (prev: " << previous->name << ")"<< endl;
}

}

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
    //Country* newCountry = new Country;
    insertCountry(NULL, "United States");
    insertCountry(searchNetwork("United States"), "Canada");
    insertCountry(searchNetwork("Canada"), "Brazil");
    insertCountry(searchNetwork("Brazil"), "India");
    insertCountry(searchNetwork("India"), "China");
    insertCountry(searchNetwork("China"), "Australia");
}

/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryNameme name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 */

// REFERENCED AND MODIFIED Prof Ashraf's Lecture 9-11 Slides FOR FUNCTION
Country* CountryNetwork::searchNetwork(string countryName) {
    Country* current = head;
    while (current!= NULL){
        if (current->name == countryName){
            return current;
        }
        current = current->next;
    }
    return NULL;
   }

/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
void CountryNetwork::transmitMsg(string receiver, string msg)
{
    if(head == NULL){
        cout<< "Empty list" << endl;
    }
    else if (searchNetwork(receiver) == NULL){
        cout << "Country not found" << endl;
    }
    else{
        Country* current = head;
        current = head;
        while(current != 0){
            current->message = msg;
            current->numberMessages = current->numberMessages + 1;
            cout << current->name << " [# messages received: " << current->numberMessages << "] received: " << current->message << endl;

            if (current->name == receiver)
            {
                break;
            }
            current = current->next; 
        }
    }
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath()
{
    cout << "== CURRENT PATH ==" << endl;
    Country* current = head;
    if (head == NULL) {
        cout<< "nothing in path" << endl;
        cout << "===" << endl;
    }
    else {
        while(current != 0){
            if (current != NULL){
                cout << current->name << " -> ";
            }
            current = current->next;
        }
    cout << "NULL" << endl;
    cout << "===" << endl;
    }
}