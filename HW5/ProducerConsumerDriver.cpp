/****************************************************************/
/*                Producer Consumer Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "ProducerConsumer.hpp"
#include <iostream>
#include <fstream> 
// you may include more libraries as needed
using namespace std;

ProducerConsumer:: ProducerConsumer(){
	queueFront = 0;
	queueEnd = 0;
}

bool ProducerConsumer:: isEmpty(){
	if(queue[queueEnd] == "" && queueFront == queueEnd){
		return true;
	}
	else{
		return false;
	}
}

bool ProducerConsumer:: isFull(){
	if(queueEnd == queueFront && queueSize() == 20){
		return true;
	}
	else {
		return false;
	}
}
void ProducerConsumer:: enqueue(std::string item){
	if(!isFull()){
		queue[queueEnd] = item;
		queueEnd = (queueEnd + 1) % SIZE;
		counter++;
	}
	else{
		cout<< "Queue full, cannot add new item"<< endl;
	}
}

void ProducerConsumer:: dequeue(){
	if(!isEmpty()){
		queue[queueFront] = "";
		queueFront = (queueFront+1) % SIZE;
		counter--;
	}
	else {
	    cout << "Queue empty, cannot dequeue an item" << endl;
	}
}

string ProducerConsumer:: peek(){
	if(!isEmpty()){
		return queue[queueFront];
	}
	else {
		cout << "Queue empty, cannot peek" << endl;
		return "";
	}
}
int ProducerConsumer:: queueSize(){ //changed
	return counter;
}

// Use getline for reading
void menu()
{
    cout << "*----------------------------------------*" << endl;
    cout << "Choose an option:" << endl;
    cout << "1. Producer (Produce items into the queue)" << endl;
    cout << "2. Consumer (Consume items from the queue)" << endl;
    cout << "3. Return the queue size and exit" << endl;
    cout << "*----------------------------------------*" << endl;
}
// Use getline for reading
int main(int argc, char const *argv[])
{
    ProducerConsumer user;
    string userInput;
    bool check = true;

while(check == true){
    menu();
    getline(cin,userInput);
    int input = stoi(userInput);
    
    if(input == 1) {
        string itemsTotal;
        string itemVal;
        int itemNumber = 1;
        cout << "Enter the number of items to be produced:" << endl;
        getline(cin,itemsTotal);
        int total = stoi(itemsTotal);

        for (int i = 0; i<total; i++){
            cout << "Item" << itemNumber << ":" << endl;
            getline(cin, itemVal);
            user.enqueue(itemVal);
            itemNumber++;
        }
    }
    else if(input == 2) {
        cout << "Enter the number of items to be consumed:" << endl;
        string removeTotal;
        getline(cin, removeTotal);
        int total = stoi(removeTotal);

        for (int i = 0; i<total; i++){
            if (i == user.queueSize()){
                cout << "No more items to consume from queue" << endl;
                i = total;
            }
            else {
                cout<<"Consumed: "<< user.peek() << endl;
                user.dequeue();
                total--;
                i--;
            }
        }
    }
    else if(input == 3) {
        cout << "Number of items in the queue:" << user.queueSize()<< endl;
        check = false;
    }
}
return 0;
}