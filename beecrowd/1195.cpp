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
        cout << " " << node->val;
        print_helper(node->right);
    }
};

void prePrint (Node *node) {
    if (node == nullptr)return;

    cout << " " << node->val;
    prePrint(node->left);
    prePrint(node->right);
}

void posPrint(Node *node) {
    if (node == nullptr)return;

    posPrint(node->left);
    posPrint(node->right);
    cout << " " << node->val;
}

int main () {
    int testcases;
    cin >> testcases;

    for (int i = 1; i <= testcases; i++) {
        int len;
        cin >> len;
        Tree nums;
        while (len--) {
            int x;
            cin >> x;
            nums.insert(x);
        }
        cout << "Case " << i << ":\n";
        cout << "Pre.:";
        prePrint(nums.root);
        cout << "\nIn..:";
        nums.print();
        cout << "\nPost:";
        posPrint(nums.root);

        cout << "\n\n";
    }
    return 0;
}