#include <cstring>
#ifndef NODE_H
#define NODE_H
using namespace std;

class Node {
 private:
  char datac;
  int datai;
  Node* next;
  public:
  Node(char input);
  Node(int input);
  ~Node();
  void setNext(Node* newnode);
  Node* getNext();
  char getDatac();
  int getDatai();
};

#endif
