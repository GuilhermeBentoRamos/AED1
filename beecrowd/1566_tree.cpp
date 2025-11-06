#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node(): val(0), left(nullptr), right(nullptr) {}
    Node(int x): val(x), left(nullptr), right(nullptr) {}
};

struct Tree {
    Node* root;

public:
    Tree(): root(nullptr) {}  
    
    ~Tree() {
        liberarMemoria(root);
    }

    void insert(int x) {
        insert_helper(root, x);
    }

    void print() {
        print_helper(root);
    }

private:
    void insert_helper(Node*& curr, int x) {
        if (curr == nullptr) {
            curr = new Node(x);
            return;
        }

        if (x < curr->val) {
            insert_helper(curr->left, x);
        } else {
            insert_helper(curr->right, x);
        }
    }

    void liberarMemoria(Node *curr) {
        if (curr == nullptr)return;

        liberarMemoria(curr->left);
        liberarMemoria(curr->right);
        delete curr;
    }

    void print_helper(Node *node) {
        if (node == nullptr)return;
        print_helper(node->left);
        cout << node->val;
        if (node->right != nullptr && node->left != nullptr)cout << " ";
        print_helper(node->right);
    }
};

int main() {
  // --- OTIMIZAÇÃO 1: I/O Rápido ---
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int testcases;
  cin >> testcases;

  while (testcases--) {
    int people;
    cin >> people;
    Tree heights;

    for (int i = 0; i < people; i++) {
        int num;
        cin >> num;
        heights.insert(num);
    }
    
    heights.print();
  }

  return 0;
}