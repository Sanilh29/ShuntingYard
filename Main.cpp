#include <iostream>
#include "Stack.h"
#include "Node.h"
#include <stack>

using namespace std;

int precedence(char operation);

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
      if (isInteger(input[i])){
      }
      if (isOperator(input[i])){//need to create an isOperator method
      }
    }
    if (strcmp(input, "quit")){
      running = false;
    }
  }
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
