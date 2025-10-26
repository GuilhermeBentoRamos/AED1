#include <iostream>

template <typename T>
struct Node {
  T val;
  Node* next;
  Node* prev;
  Node(T v) : val(v), next(nullptr), prev(nullptr) {}
  Node(T v, Node* n) : val(v), next(n), prev(nullptr) {}
  Node(T v, Node* n, Node* p) : val(v), next(n), prev(p) {}
};

template <typename T>
struct ListNode {
  Node<T>* head;
};

template <typename T>
struct TwoWayNode {
  Node<T>* head;
  Node<T>* tail;
};

template <typename T>
struct Stack {
  Node<T>* head;
  Node<T>* tail;
};

template <typename T>
struct Queue {
  Node<T>* head;
  Node<T>* tail;
};

template <typename T>
struct Stack {
  Node<T>* head;
  Node<T>* tail;
};