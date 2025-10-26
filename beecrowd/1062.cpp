#include <iostream>
using namespace std;

struct Node {
  int val;
  Node* next;
  Node(int x) : val(x), next(nullptr) {}
  Node(int x, Node* prox) : val(x), next(prox) {}
};

struct Stack {
  Node* top;
  Stack() : top(nullptr) {}
};

void pop(Stack& curr) {
  if (curr.top == nullptr)
    return;
  Node* trash = curr.top;
  curr.top = curr.top->next;
  delete trash;
}

void push(Stack& curr, int val) {
  Node* newNode = new Node(val);
  newNode->next = curr.top;
  curr.top = newNode;
}

int top(Stack& curr) {
  if (curr.top == nullptr)
    return 0;
  return curr.top->val;
}

int main() {
  int n;
  while (cin >> n && n != 0) {
    int first;
    int* target = new int[n];
    while (cin >> first && first != 0) {
      target[0] = first;
      for (int i = 1; i < n; i++) {
        cin >> target[i];
      }
      Stack wagons;
      int ptr = 0;
      for (int i = 1; i <= n; i++) {
        push(wagons, i);
        while (ptr < n && top(wagons) == target[ptr]) {
          pop(wagons);
          ptr++;
        }
      }

      cout << (top(wagons) == 0 ? "Yes" : "No") << endl;
    }
    cout << endl;
    delete[] target;
  }
}