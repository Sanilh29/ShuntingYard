#include <cstring>
using namespace std;

class Node {
 private:
  char data;
  char input;
  Node* next;
  public:
  Node(char data);
  ~Node();
  void setNext(Node* newnode);
  Node* getNext();
  char getInput();
};
