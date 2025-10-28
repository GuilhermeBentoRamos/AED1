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

struct ListNode {
  Node *head;
  ListNode() : head(nullptr) {} 
};

//adiciona item a lista já ordenando. Similar a um set
void push(ListNode& nums, int x, int i) {
  Node *newNode = new Node(x, i);

  if (nums.head == nullptr || nums.head->val < x) {
    newNode->next = nums.head;
    nums.head = newNode;
    return;
  }

  Node *curr = nums.head;
  while (curr->next != nullptr && curr->next->val >= x) {
    curr = curr->next;
  }

  newNode->next = curr->next;
  curr->next = newNode;
}

// Função para limpar a memória da lista (evitar memory leak)
void clearList(ListNode& nums) {
  Node *curr = nums.head;
  while (curr != nullptr) {
    Node *temp = curr;
    curr = curr->next; 
    delete temp;       
  }
  nums.head = nullptr;
}

int main() {
  int testCases;
  cin >> testCases;
  for (int m = 0; m < testCases; m++) {
    int len;
    cin >> len;
    
    ListNode nums; 
    
    for (int i = 0; i < len; i++) {
      int num;
      cin >> num;
      push(nums, num, i);
    }

    Node *curr = nums.head;
    int counter = 0;
    for (int i = 0; i < len; i++) {
      if (i == curr->index) { 
        counter++;
      }
      if (curr != nullptr) {
          curr = curr->next;
      }
    }
    
    cout << counter << endl; 

    clearList(nums);
  }
  return 0; 
}