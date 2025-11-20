#include <iostream>
using namespace std;

struct Node {
  int val;
  Node* next;
  Node() : val(0), next(nullptr) {}
  Node(int val) : val(val), next(nullptr) {}
  Node(int val, Node* next) : val(val), next(next) {}
};

struct ListNode {
  Node* head;

 public:
  ListNode() : head() {}

  void insert(int x) {
    if (head == nullptr) {
      head->val = x;
      return;
    }
    Node* curr = head;
    while (curr->next != nullptr) {
      curr = curr->next;
    }
    Node* newNode = new Node(x);
    curr->next = newNode;
  }

  void pop() {
    Node* curr = head;
    while (curr->next != nullptr) {
      curr = curr->next;
    }
    delete curr;
  }

  ~ListNode() {
    while (head != nullptr) {
      pop();
    }
  }
};

int main() {
  // Otimização de I/O (Essencial para C++ no Beecrowd)
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        ListNode
    }
  }
}
