#include <cstring>
#include "Node.h"
using namespace std;

Node::Node(char data){
  data =input;
  next = NULL;
}

Node::~Node(){
  next = NULL;
}

void Node::setNext(Node* newnode){
  next = newnode;
}

Node* Node::getNext(){
  return next;
}

char Node::getInput(){
  return input;
}



