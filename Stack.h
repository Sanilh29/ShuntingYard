//Sanil Hattangadi, stack header that initialized variables and methods
#include "Node.h"

using namespace std;

class Stack{
 private://variables
  Node* head;
 public://methods
  Stack();//constructor
  ~Stack();//deconstructor
  Node* peek();//looks at top node of stack
  Node* push(Node* newnode);//pushes a node to the top of a stack
  Node* pop();//removes node from top of stack
};
