/****************************************************************/
/*                  RPN Calculator Driver File                  */
/****************************************************************/
/*      TODO: Implement driver as described in the writeup      */
/****************************************************************/

#include "RPNCalculator.hpp"
#include <iostream>
// you may include more libraries as needed

using namespace std;

RPNCalculator:: RPNCalculator(){
    stackHead = NULL;
}

RPNCalculator:: ~RPNCalculator(){
    while(!isEmpty()){
      pop();
    }
}

bool RPNCalculator:: isEmpty(){
  return (stackHead == NULL);
}

void RPNCalculator:: push(float num){
  if(!isEmpty()){
    Operand *temp = new Operand;
    temp->number = num;
    temp->next = stackHead;
    stackHead = temp;
  }
  else {
    Operand *temp = new Operand;
    temp->number = num;
    temp->next = NULL;
    stackHead = temp;
  }
}

void RPNCalculator:: pop(){
    if (!isEmpty()){
        Operand *temp = stackHead;
        stackHead = stackHead->next;
        delete temp;
    }
    else {
        cout << "Stack empty, cannot pop an item." << endl;
    }
}

Operand* RPNCalculator:: peek(){
  if (!isEmpty()){
    return stackHead;
  }
  else {
    cout << "Stack empty, cannot peek." << endl;
    return NULL;
  }
}

bool RPNCalculator:: compute(std::string symbol){
  int switchCheck = 0;
  if(isEmpty() || stackHead ->next == NULL){
    cout << "err: not enough operands" << endl;
    return false;
  }
  if(symbol == "+"){
    switchCheck = 1;
  }
  else if(symbol == "*"){
    switchCheck = 2;
  }
  switch(switchCheck){
    case 1:
      stackHead->next->number = stackHead->number + stackHead->next->number;
      pop();
      return true;
    break;

    case 2:
      stackHead->next->number = stackHead->number * stackHead->next->number;
      pop();
      return true;
    break; 

    default:
      cout << "err: invalid operation" << endl;
      return false;
    break;
    }
}

/*
 * Purpose: Determine whether some user input string is a
 *          valid floating point number
 * @param none
 * @return true if the string s is a number
 */
bool isNumber(string s)
{
    if(s.size() == 1 && s == "-") return false;
    else if(s.size() > 1 && s[0] == '-') s = s.substr(1);

    bool point = false;
    for(int i = 0; i < s.size(); i++)
    {
      if(!isdigit(s[i]) && s[i] != '.') return false;
      if(s[i]=='.' and !point) point = true;
      else if(s[i]=='.' and point) return false;
    }

    return true;
}

int main()
{
  // TODO - Declare a stack to hold the operands
  RPNCalculator calculator;
  calculator = RPNCalculator();
  string input;
  cout << "Enter the operators and operands ('+', '*') in a postfix format" << endl;

  while(true)
  {
    cout << "#> ";
    getline(cin, input);
  /* TODO
      1. Read input (operators and operands) until you encounter a "="
      2. Use the isNumber function to check if the input is an operand
      3. push all operands to the stack
      4. If input is not an operand, call the compute function to evaluate
        the partial expression
  */
    if (input == "="){
      break;
    }
    if(isNumber(input)){

      calculator.push(stof(input));
    }
    else{
      calculator.compute(input);
    }
  }

/* TODO - If the stack is empty then print "No operands: Nothing to evaluate" */
  if(calculator.isEmpty()){
    cout << "No operands: Nothing to evaluate" << endl;
    return 0;
  }

/* TODO - Validate the expression
    1. If valid then print the result
    2. Else, print "Invalid expression"*/
  if(calculator.getStackHead() -> next != NULL) {
      cout << "Invalid expression" << endl;
  }
  else {
    cout << calculator.getStackHead() -> number << endl;
  }
  return 0;
}