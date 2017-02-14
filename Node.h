using namespace std;

class Node {
 private:
  Node* node;
  public:
  Node();
  ~Node();
  void setNext(Node* newnode);
  Node* getNext();
  
};
