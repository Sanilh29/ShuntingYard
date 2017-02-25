#include <iostream>
#include "Stack.h"
#include "Node.h"
#include <stack>
#include <stdlib.h>

using namespace std;

int precedence(char operation);
bool isOperator(char o);
Stack* shuntingYard(char* input);

int main(){
  char command[32];
  bool running = true;
  while (running == true){
    cout << "Enter a command please: translate or quit." << endl;
    cin.get(command, 32);
    cin.ignore();
    if (0 == strcmp(command, "translate")){
      char input[100];
      cout << "Enter an equation please" << endl;
      cin.get(input, 100);
      shuntingYard(input);
      running = false;
    }
    if (0 == strcmp(command, "quit")){
      running = false;
    }
  }
}

Stack* shuntingYard(char* input){
  Stack* outputStack = new Stack();
  Stack* operatorStack = new Stack();
  int i = 0;//start counting at the first input
  while (input[i]){
    //cout << input << endl;
    if (isdigit(input[i])){//if the input is a number
      outputStack->push(new Node(atoi(&input[i])));
      cout << outputStack->peek()->getDatai() << " ";
      while(isdigit(input[i+1])){//go to end of the number
	i++;
      }
    }
    if (isOperator(input[i])){ //if its a + - * / ^
      while (operatorStack->peek()){
	Node* o2 = operatorStack->peek();
	if (precedence(input[i]) >= precedence(o2->getDatai())){
	  break;
	}
	outputStack->push(operatorStack->pop());
	cout << outputStack->peek()->getDatac() << " ";
      }
      operatorStack->push(new Node(input[i]));
    }
    if (input[i] == '('){ //if the input is (
      operatorStack->push(new Node(input[i]));
    }
    else if (input[i] == ')'){ //if the input is )
      while(operatorStack->peek()->getDatac() != '('){
	outputStack->push(operatorStack->pop());
	cout << outputStack->peek()->getDatac() << " ";
      }
      delete operatorStack->pop();
    }
    i++; //go the the next value in the input
  }
  while(operatorStack->peek()){
    outputStack->push(operatorStack->pop());
    cout << outputStack->peek()->getDatac() << " ";
  }
  cout << endl;
  delete operatorStack;
  return outputStack;
}

bool isOperator (char o){//check to see if its an operator (+ - * / ^)
  if (o == '+' || o == '-' || o == '*' || o == '/' || o == '^'){
    return true;
  }
  return false;
}

int precedence(char operation){ //setting PEMDAS essentially. the greater the value, the more precedence
  int precedence[256] = {};
    precedence ['+'] = 1;
    precedence ['-'] = 1;
    precedence ['*'] = 2;
    precedence ['/'] = 2;
    precedence ['^'] = 3;
    return precedence[operation];
}
