/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represent communication paths between nations             */
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
/* finished. do not touch. */
    head = NULL;
}


/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CountryNetwork::isEmpty()
{
/* finished. do not touch. */
    return (head == NULL);
}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName) {
    
    // if we are passed an empty list, just create a new head node, and return
    if (head == NULL)
    {
        cout << "adding: " << countryName << " (HEAD)" << endl;
        head = new Country;
        head->name = countryName;
        head->numberMessages = 0;
        head->next = NULL;
    }
    // if it's not empty, we need to search for previous and append our node there.
    else if(previous == NULL )
    {
        //case where it's a new head Country
        cout << "adding: " << countryName << " (HEAD)" << endl;
        Country *c = new Country;
        c->name = countryName;
        c->numberMessages = 0;
        c->next = head;
        head = c;
    }else{
        cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;
        Country *newCountry = new Country;
        newCountry->name = countryName;
        newCountry->numberMessages = 0;
        newCountry->next = previous->next;
        previous->next = newCountry;
    }
}


/*
 * Purpose: delete the country in the network with the specified name.
 * @param countryName name of the country to delete in the network
 * @return none
 */
// REFERENCED PROF ASHRAF CODE TO DELETE NODES
void CountryNetwork::deleteCountry(string countryName) {
    //TODO: Complete this function
    Country* temp = searchNetwork(countryName);
    if (temp == 0) {
        cout << "Country does not exist." << endl;
    }
    if(head -> name == countryName){
        Country* temp = head;
        head = head -> next;
        delete temp;
    }
    else{
        Country* left= head;
        Country* temp = left -> next;
        bool isFound = false;
        while (temp!=0 && isFound != true){
            if (temp->name == countryName){ //tail node
                if (temp-> next == 0){
                    left -> next = 0;
                    //tail=left;
                }
                else {
                    left -> next = temp->next;
                }
                delete temp;
                isFound = true;
            }
            else {
                left = temp;
                temp = temp ->next;
            }
        }
    }
}

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
    int num_countries = 6;
    string countries[] = {"United States", "Canada", "Brazil", "India", "China", "Australia"};
    // deleteEntireNetwork();
    Country* prev = NULL;
    for(int i = 0; i < num_countries; i++)
    {
        insertCountry(prev, countries[i]);
        prev = searchNetwork(countries[i]);
    }
}


/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 * @see insertCountry, deletecountry
 */
Country* CountryNetwork::searchNetwork(string countryName)
{
// Search until the head is NULL, or we find the country
    Country* ptr = head;
    while (ptr != NULL && ptr->name != countryName)
    {
        ptr = ptr->next;
    }
    // Return the node, or NULL
    return ptr;
}

/*
* Purpose: Creates a loop from last node to the country specified.
* @param countryName name of the country to loop back
* returns pointer to last node before loop creation (to break the loop)
*/

Country* CountryNetwork::createLoop(string countryName)
{
    Country* current = head;
    Country* loop = head;
    
    loop = searchNetwork(countryName);

    if (loop == NULL){
        return loop;
    }
    else {
        while(current -> next != NULL){ // dont want to go all the way to NULL just right before
            current = current -> next;
        } 
        current-> next = loop;
        return current;
    } 
}

/*
 * Purpose: deletes all countries in the network starting at the head country.
 * @param none
 * @return none
 */
void CountryNetwork::deleteEntireNetwork()
{
    Country* ptr = head;
    bool finished = false;
    
    while (head != NULL){
        string countryName = ptr -> name;
        cout<< "deleting: " << ptr-> name << endl;
        ptr = ptr -> next;
        deleteCountry(countryName);
        finished = true;
    }
    if (finished == true){
        cout << "Deleted network" << endl;
    }
}

/*
*Purpose: to detect loop in the linkedlist
* @param
* returns true if loop is detected. Otherwise return false.
*/
bool CountryNetwork::detectLoop() {
    //TODO: Complete this function
    //detect the loop
    //detect the start of loop
    Country* s = head; // one node at a time
    Country* f = head; // two nodes at a time

    while(f != NULL) {
        s = s->next;
        f = f->next->next;
        if (s==f){
            return true;
        }
    }
    return false;
}

/*
* Purpose: Take the chunk of nodes from start index to end index
*          Move that chunk at the end of the List
*@param: start index
*@param: end index
* return none
*/
void CountryNetwork:: readjustNetwork(int start_index, int end_index)
{
    Country* count = head;
    int total = 0;
    while(count != NULL){
        total++;
        count = count -> next;
    }

    if (total == 0) {
        cout << "Linked List is Empty" << endl;
    }
    else if (end_index < 0 || end_index>total) {
        cout << "Invalid end index" << endl;
    }
    else if(start_index > total || start_index < 0){
        cout << "Invalid start index" << endl;
    }
    else if( start_index > end_index){
        cout << "Invalid indices" << endl;
    }
    else{
        Country* current = head;
        Country* pcurrent = head;
        Country* previous = head;
        Country* previous_ = head;
        for(int i = 0; i<start_index-1; i++){
            previous = previous-> next;
        }
        for (int j = 0; j < (start_index+end_index-1); j++){
            pcurrent = pcurrent-> next; 
        }
        for (int k = 0; k < (start_index+end_index); k++){
            current = current-> next; 
        }
        pcurrent -> next = current ->next;
        current -> next = previous -> next;
        previous -> next = current;
    }
} 

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath() {
    cout << "== CURRENT PATH ==" << endl;
    // If the head is NULL
    Country* ptr = head;
    if (ptr == NULL)
        cout << "nothing in path" << endl;

    // Otherwise print each node, and then a NULL
    else
    {
        while (ptr->next != NULL)
        {
            cout << ptr->name << " -> ";
            ptr = ptr->next;
        }
        cout << ptr->name << " -> ";
        cout << "NULL" << endl;
    }
    cout << "===" << endl;
}
