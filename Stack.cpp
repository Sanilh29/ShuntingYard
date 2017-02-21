#include <cstring>
#include "Stack.h"

using namespace std;

Stack::Stack(){
  head = NULL;
}

Stack::~Stack(){
  Node* nextNode = head;
  while (head != NULL){
    nextNode = head->getNext();
    delete head;
    nextNode = head;
  }
}

Node* Stack::peek(){//
  return head;
}

Node* Stack::push(Node* newnode){//
  newnode->setNext(head);
  head = newnode;
}

Node* Stack::pop(){//
  Node* popNode = head;
  head = popNode->getNext();
  return popNode;
}
