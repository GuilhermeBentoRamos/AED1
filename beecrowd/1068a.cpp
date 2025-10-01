#include <iostream>
#include <string>
using namespace std;

int main() {
  string expression;
  while (getline(cin, expression)) {
    bool valid = true;
    int counter = 0;
    for (char c : expression) {
      if (c != '(' && c != ')' || !valid)
        continue;
      if (c == '(') {
        counter++;
      } else if (counter == 0) {
        valid = false;
      } else {
        counter--;
      }
    }
    if (counter != 0)
      valid = false;
    if (valid)
      cout << "correct" << endl;
    else
      cout << "incorrect" << endl;
  }
}