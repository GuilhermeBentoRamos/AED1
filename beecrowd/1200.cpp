#include <iostream>
#include <string>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(), left(nullptr), right(nullptr) {}
  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
  TreeNode(int val, TreeNode* left, TreeNode* right)
      : val(val), left(left), right(right) {}
};

struct Tree {
  TreeNode* root;

 public:
  Tree() : root(nullptr) {}

  ~Tree() { destruct(root); }

  void printInfix() {
    bool first = true;
    infix(root, first);
  }

  void printPrefix() {
    bool first = true;
    prefix(root, first);
  }

  void printPos() {
    bool first = true;
    posfix(root, first);
  }

  void insert(int val) { insertHelper(root, val); }

  bool find(int val) { return findHelper(root, val); }

 private:
  void destruct(TreeNode* node) {
    if (node == nullptr) {
      return;
    }
    destruct(node->left);
    destruct(node->right);
    delete node;
  }

  void infix(TreeNode* node, bool& first) {
    if (node == nullptr) return;
    infix(node->left, first);
    if (!first) std::cout << " ";
    std::cout << static_cast<char>(node->val);
    first = false;
    infix(node->right, first);
  }

  void prefix(TreeNode* node, bool& first) {
    if (node == nullptr) return;
    if (!first) std::cout << " ";
    std::cout << static_cast<char>(node->val);
    first = false;
    prefix(node->left, first);
    prefix(node->right, first);
  }

  void posfix(TreeNode* node, bool& first) {
    if (node == nullptr) return;
    posfix(node->left, first);
    posfix(node->right, first);
    if (!first) std::cout << " ";
    std::cout << static_cast<char>(node->val);
    first = false;
  }

  void insertHelper(TreeNode*& node, int val) {
    if (node == nullptr) {
      node = new TreeNode(val);
      return;
    }
    if (val < node->val) {
      insertHelper(node->left, val);
    } else {
      insertHelper(node->right, val);
    }
  }

  bool findHelper(TreeNode* node, int val) {
    if (node == nullptr) return false;
    if (node->val == val) return true;
    if (val < node->val) {
      return findHelper(node->left, val);
    } else {
      return findHelper(node->right, val);
    }
  }
};

int main() {
  std::string comand;
  Tree letters;
  while (std::getline(std::cin, comand)) {
    if (comand.empty()) continue;

    if (comand == "INFIXA") {
      letters.printInfix();
      std::cout << std::endl;
    } else if (comand == "PREFIXA") {
      letters.printPrefix();
      std::cout << std::endl;
    } else if (comand == "POSFIXA") {
      letters.printPos();
      std::cout << std::endl;
    } else if (comand[0] == 'I') {
      letters.insert(static_cast<int>(comand[2]));
    } else {
      std::cout << comand[2] << " ";
      std::cout << (letters.find(static_cast<int>(comand[2])) ? "existe"
                                                              : "nao existe")
                << std::endl;
    }
  }
  return 0;
}