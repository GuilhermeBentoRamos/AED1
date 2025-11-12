#include <iostream>
using namespace std;

struct Node {
  int val;
  Node* next;
  Node() : val(0), next(nullptr) {}
  Node(int x) : val(x), next(nullptr) {}
  Node(int x, Node* node) : val(x), next(node) {}
};

int main() {
  int testcases;
  cin >> testcases;
  for (int i = 1; i <= testcases; i++) {
    int n, k;
    cin >> n >> k;

    // criação de uma lista circular com o auxílio de um nó sentinela
    Node* list = new Node(1);
    Node* dummy = new Node(0, list);
    for (int j = 2; j <= n; j++) {
      list->next = new Node(j);
      list = list->next;
    }
    list->next = dummy->next;

    for (int j = 0; j < n - 1; j++) {
      for (int a = 0; a < k - 1; a++) {
        list = list->next;
      }
      Node* trash = list->next;
      list->next = trash->next;
      delete trash;
    }
    cout << "Case " << i << ": " << list->val << endl;
    delete list;
    delete dummy;
  }
}