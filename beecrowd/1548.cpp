#include <iostream>
using namespace std;

struct Node {
  int val;
  int index;
  Node* next;
  Node() : val(0), index(0), next(nullptr) {}
  Node(int x, int i) : val(x), index(i), next(nullptr) {}
  Node(int x, int i, Node* n) : val(x), index(i), next(n) {}
};

// esrtrutura de dados baseado em uma fila de prioridade
struct Data {
  Node* head;
  Node* tail;
  Data() : head(nullptr), tail(nullptr) {}
};

void push(Data& nums, int x) {}

int main() {
  int testCases;
  cin >> testCases;
  for (int m = 0; m < testCases; i++) {
    int len;
    cin >> len;
    for (int i = 0; i < len; i++) {
      int num;
      cin >> num;
    }
  }
}