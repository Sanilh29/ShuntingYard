#include <cstring>
#include "Node.h"
using namespace std;

Node::Node(int input){
  datai = input;
  next = NULL;
}

Node::Node(char input){
  datac = input;
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

char Node::getDatac(){
  return datac;
}

int Node::getDatai(){
  return datai;
}



