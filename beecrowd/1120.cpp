#include <iostream>
#include <string>

using namespace std;

int main() {
  char x;
  string val;

  while (cin >> x >> val, x != '0' && val != "0") {
    string result = "";
    bool zeros = true;  // para controlar zeros a esquerda

    for (char c : val) {
      if (c == x) {
        continue;
      }

      if (zeros && c == '0') {
        continue;
      }

      zeros = false;
      result.push_back(c);
    }

    if (result.empty()) {
      cout << "0\n";
    } else {
      cout << result << "\n";
    }
  }

  return 0;
}