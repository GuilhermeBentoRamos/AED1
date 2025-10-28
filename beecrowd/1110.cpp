#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(int x, Node *n): val(x), next(n) {}
};

struct Stack {
    Node* top;
    Node* base;
    Stack(): top(nullptr), base(nullptr) {}
};

struct Queue {
    Node* head;
    Node* tail;
    Queue(): head(nullptr), tail(nullptr) {}
};

void push (Stack& nums, int x) {

Node *newNode = new Node(x, nums.top);

nums.top = newNode;

if (nums.base == nullptr)nums.base = newNode;

} 

void popQueue(Queue& nums) {
    Node* trash = nums.head;
    nums.head = nums.head->next;
    delete trash;
}

void pushQueue(Queue& nums, int x) {
    Node* newNode = new Node(x);
    if (nums.head == nullptr) { // Se a fila está vazia
        nums.head = newNode;
        nums.tail = newNode;
    } else { // Se a fila NÃO está vazia
        nums.tail->next = newNode;
        nums.tail = newNode; 
    }
}
void cardRemove (Stack& nums) {
    Node* trash = nums.top;
    nums.top = nums.top->next;
    delete trash;

    if (nums.top != nullptr && nums.top->next != nullptr) {
        Node* temp = nums.top;
        nums.top = nums.top->next;

        nums.base->next = temp;
        nums.base = temp;
        nums.base->next = nullptr;
    }
}

int main () {
    int n;
    while (cin >> n && n != 0) {
        Stack nums;
        for (int i = n; i > 0; i--) {
            push(nums, i);
        }
        Queue newNums;
        while (nums.top->next != nullptr) {
            int x = nums.top->val;
            pushQueue(newNums, x);
            cardRemove(nums);
        }
        cout << "Discarded cards: ";
        if (newNums.head != nullptr) {
            cout << newNums.head->val;
            popQueue(newNums);
        }
        
        while (newNums.head != nullptr) {
            cout << ", " << newNums.head->val;
            popQueue(newNums);
        }
        cout << "\n" << "Remaining card: " << nums.top->val << "\n";
        cardRemove(nums);
    }
    return 0;
}