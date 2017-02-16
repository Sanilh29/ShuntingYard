#include <cstring>
#include "Stack.h"

using namespace std;

Stack::Stack(){

}

Stack::~Stack(){

}

Node* Stack::peek(){//
  
}

Node* Stack::push(Node* newnode){//
  newnode->setNext(head);
  head = newnode;
}

Node* Stack::pop(){//
  
}
