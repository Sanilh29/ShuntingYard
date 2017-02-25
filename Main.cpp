//Sanil Hattangadi, 2/24/17
//the code takes an equation and puts it into either an ouput or operator stack using the shunting yard
#include <iostream>
#include "Stack.h"
#include "Node.h"
#include <stack>
#include <stdlib.h>

using namespace std;

//methods I use
int precedence(char operation);
bool isOperator(char o);
Stack* shuntingYard(char* input);

int main(){
  char command[32];//creates variable for input
  bool running = true;
  while (running == true){
    cout << "Enter a command please: translate or quit." << endl;
    cin.get(command, 32);//puts input into variable
    cin.ignore();
    if (0 == strcmp(command, "translate")){//if command equals translate
      char input[100];//get the equation
      cout << "Enter an equation please" << endl;
      cin.get(input, 100);
      shuntingYard(input);//run Shunting yard algorithm
      running = false;//stop program
    }
    if (0 == strcmp(command, "quit")){//if input equals quit
      running = false;//stop program
    }
  }
}

Stack* shuntingYard(char* input){//runs algorithm
  Stack* outputStack = new Stack();//creates output stack
  Stack* operatorStack = new Stack();//and operator stack
  int i = 0;//start counting at the first input
  while (input[i]){
    //cout << input << endl;
    if (isdigit(input[i])){//if the input is a number
      outputStack->push(new Node(atoi(&input[i])));//creates a new node and changes string to int
      cout << outputStack->peek()->getDatai() << " ";//prints out integer
      while(isdigit(input[i+1])){//go to end of the number
	i++;
      }
    }
    if (isOperator(input[i])){ //if its a + - * / ^
      while (operatorStack->peek()){//while there is something on operator stack
	Node* o2 = operatorStack->peek();//create node that is on top of operator 
	if (precedence(input[i]) >= precedence(o2->getDatai())){//check precedence
	  break;
	}
	outputStack->push(operatorStack->pop());//pop it
	cout << outputStack->peek()->getDatac() << " ";//print out char
      }
      operatorStack->push(new Node(input[i]));
    }
    if (input[i] == '('){ //if the input is (
      operatorStack->push(new Node(input[i]));//push it
    }
    else if (input[i] == ')'){ //if the input is )
      while(operatorStack->peek()->getDatac() != '('){//while there is a ( on the top of the operator stack
	outputStack->push(operatorStack->pop());//pop
	cout << outputStack->peek()->getDatac() << " ";//print out
      }
      delete operatorStack->pop();
    }
    i++; //go the the next value in the input
  }
  while(operatorStack->peek()){//while there is something in the operator stack
    outputStack->push(operatorStack->pop());//push the the top of operator stack
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
