#include <iostream>

template <typename T>
struct Node {
  T val;
  Node<T>* next;
  Node() : val(), next(nullptr) {}
  Node(T val) : val(val), next(nullptr) {}
  Node(T val, Node<T>* next) : val(val), next(next) {}
};

template <typename T>
class Stack {
 private:
  Node<T>* top;

 public:
  Stack() : top(nullptr) {}

  ~Stack() {
    while (!empty()) {
      pop();
    }
  }

  void push(T x) {
    Node<T>* newNode = new Node<T>(x, top);
    top = newNode;
  }

  void pop() {
    if (empty()) return;
    Node<T>* temp = top;
    top = top->next;
    delete temp;
  }

  bool empty() { return !top; }

  T peek() { return top->val; }
};