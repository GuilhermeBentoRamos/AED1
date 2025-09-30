#include <iostream>
#include <string>
using namespace std;

struct Node {
  char val;
  Node* next;
  Node() : val(0), next(nullptr) {}
  Node(char c) : val(c), next(nullptr) {}
  Node(char c, Node* nextNode) : val(c), next(nextNode) {}
};

void push(Node* dummyHead, char c) {
  Node* newNode = new Node(c);
  Node* curr = dummyHead;
  while (curr->next != nullptr) {
    curr = curr->next;
  }
  curr->next = newNode;
}

int pop(Node* dummyHead) {
  if (dummyHead->next == nullptr)
    return 0;

  Node* curr = dummyHead;
  while (curr->next->next != nullptr) {
    curr = curr->next;
  }
  Node* trash = curr->next;
  curr->next = nullptr;
  delete trash;
  return 1;
}

void destruct(Node* dummyHead) {
  while (dummyHead->next != nullptr)
    pop(dummyHead);
}

int main() {
  string expression;
  while (getline(cin, expression)) {
    Node* dummyHead = new Node();
    bool valid = true;
    for (char c : expression) {
      if (c != '(' && c != ')' || !valid)
        continue;

      if (c == '(') {
        push(dummyHead, c);
      } else {
        if(!pop(dummyHead))
          valid = false;
      }
    }

    if(dummyHead->next != nullptr)
      valid = false;
    if (valid)
      cout << "correct" << endl;
    else
      cout << "incorrect" << endl;
    destruct(dummyHead);
    delete dummyHead;
  }
}