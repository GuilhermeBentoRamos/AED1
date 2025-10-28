#include <iostream>
using namespace std;

struct Node {
  int val;
  Node* next;
  Node* prev;
  Node(int x): val(x), next(nullptr), prev(nullptr) {}
  Node(int x, Node* p, Node* n): val(x), next(n), prev(p) {}
};

struct ListNode {
  Node* head;
  Node* tail;
  ListNode() : head(nullptr), tail(nullptr) {}
};

void push_back(ListNode& nums, int x) {
    Node *newNode = new Node(x);
    if (nums.head == nullptr) {
      nums.head = newNode;
      nums.tail = newNode;
      return;
    }
    
    nums.tail->next = newNode;
    newNode->prev = nums.tail;
    nums.tail = newNode;
}

void pop(ListNode& nums, int x) {
    Node *curr = nums.head;
    while (curr != nullptr && curr->val != x) {
        curr = curr->next;
    }

    if (curr == nullptr) {
      return;
    }
    
    if (curr->prev != nullptr){
      curr->prev->next = curr->next;
    } else {
      nums.head = curr->next;
    }

    if (curr->next != nullptr){
      curr->next->prev = curr->prev;
    } else {
      nums.tail = curr->prev;
    }

    delete curr;

    if (nums.head == nullptr) {
      nums.tail = nullptr;
    }
}

void destruct (ListNode& nums) {
  Node *curr = nums.head;
  while (curr != nullptr) {
    Node *trash = curr;
    curr = curr->next;
    delete trash;
  }
  nums.head = nullptr;
  nums.tail = nullptr;
}

int main () {
    int n; 
    cin >> n;
    ListNode queue;
    while (n--) {
      int x;
      cin >> x;
      push_back(queue, x);
    }

    int m;
    cin >> m;
    while (m--) {
      int x;
      cin >> x;
      pop (queue, x);
    }

    Node* curr = queue.head;
    while (curr != nullptr) {
      cout << curr->val;

      if (curr->next != nullptr) {
        cout << " ";
      }
      curr = curr->next;
    }
    cout << endl;

    destruct (queue);
    return 0;
}