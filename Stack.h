#include "Node.h"
using namespace std;

class Stack{
 private:
  Node* head;
 public:
  Stack();
  ~Stack();
  Node* peek();
  Node* push(Node* newnode);
  Node* pop();
};
