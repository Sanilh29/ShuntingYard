#include <iostream>
#include "Stack.h"
#include "Node.h"
#include <stack>
#include <stdlib.h>

using namespace std;

int precedence(char operation);
bool isOperator(char o);

int main(){
  char input[32];
  cout << "Enter a command please: quit or translate." << endl;
  cin >> input;
  bool running = true;
  Stack* outputStack = new Stack();
  Stack* operatorStack = new Stack();
  while (running == true){
    if (strcmp("translate", input)){
      char equation[100];
      cout << "Enter an equation please." << endl;
      cin.get(equation, 100);
      cin.ignore();
      int i = 0;
      while(input[i+1] != '\0'){
	if (isdigit(input[i])){
	  outputStack->push(new Node(atoi(&input[i])));
	}
	if (isOperator(input[i])){
	  Node* o2 = operatorStack->peek();
	  Node* o1 = new Node(atoi(&input[i]));
	  if (precedence(o1->getData()) < precedence(o2->getData())){
	    operatorStack->pop();
	    outputStack->push;
	  }
	  if (precedence(i) > precedence(o2->getData())){
	  
	  }
	}
	if (input[i] == '('){
	  outputStack->push(new Node(atoi(&input[i])));
	}
	if (input[i] == ')'){
	  
	}
      }
    }
    if (strcmp(input, "quit")){
      running = false;
    }
  }
}

bool isOperator (char o){
  if (o == '+' || o == '-' || o == '*' || o == '/' || o == '^'){
    return true;
  }
  return false;
}

int precedence(char operation){
  int precedence[256] = {};
    precedence ['+'] = 1;
    precedence ['-'] = 1;
    precedence ['*'] = 2;
    precedence ['/'] = 2;
    precedence ['^'] = 3;
    return precedence[operation];
}
