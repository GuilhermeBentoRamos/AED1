#include <iostream>
using namespace std;

struct Node {
  int val;
  Node* next;
  Node(int x) : val(x), next(nullptr) {}
  Node(int x, Node* n) : val(x), next(n) {}
};

struct ListNode {
  Node* head;
};

// remover item da pos n de uma lista encadeada sem cabeça
// O(n)
void BuscaERemove(ListNode& list, int n) {
  // apesar de estrutura de ListNode ter yum "head" ele é apenas o primeiro item
  // dummyHead é um ponteiro para o primeiro item da lista, ou seja, o head
  Node* dummyHead = new Node(0, list.head);
  Node* curr = dummyHead;

  // loop para chegar no nó anterior ao que se quer remover
  while (curr->next != nullptr && curr->next->val != n)
    curr = curr->next;

  // remover nó desejado
  Node* trash = curr->next;

  if (trash != nullptr) {
    curr->next = trash->next;
    delete trash;
  }

  list.head = dummyHead->next;
  delete dummyHead;
}

// inserir um valor x logo apos um valor n em uma lista sem cabeça
// O(n)
void BuscaEInsere(ListNode& list, int n, int x) {
  Node* curr = list.head;
  // buscar no com valor n
  while (curr != nullptr && curr->val != n)
    curr = curr->next;
  if (curr == nullptr)
    return;  // protecao pra caso n nao esteja na lista

  // criar e inserir novo no
  Node* newNode = new Node(x, curr->next);
  curr->next = newNode;
}

// remover de uma lista todas aparições de um valor
void removerTodos(ListNode& list, int n) {
  Node* dummyHead = new Node(0, list.head);
  Node* curr = dummyHead->next;
  while (curr->next != nullptr) {
    if (curr->next->val = n) {
      Node* trash = curr->next;
      if (trash != nullptr) {
        curr->next = trash->next;
        delete trash;
      }
    }
    curr = curr->next;
  }
  list.head = dummyHead->next;
  delete dummyHead;
}