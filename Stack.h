using namespace std;

class Stack{
 private:
  char operation;
 public:
  Stack();
  ~Stack()
  char getOperation();
  Node* peek();
  Node* push();
  Node* pop();
};
