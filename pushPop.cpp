#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* nextNode) : val(x), next(nextNode) {}
};

// insert (val, lastNode) = push/push_back. insert (val, dummyHead) para add o
// primeiro nó
void insert(int x, ListNode* previusNode) {
  if (previusNode == nullptr)
    return;
  ListNode* newNode = new ListNode(x, previusNode->next);
  previusNode->next = newNode;
}

ListNode* pop(ListNode* head, ListNode* trash) {
  if (head == nullptr || trash == nullptr)
    return head;

  if (head == trash) {
    ListNode* new_head = trash->next;
    delete trash;
    return new_head;
  }

  ListNode* prev = head;
  while (prev != nullptr && prev->next != trash) {
    prev = prev->next;
  }

  if (prev->next == nullptr)
    return head;

  prev->next = trash->next;
  delete trash;
  return head;
}

int main() {}