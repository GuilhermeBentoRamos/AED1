#include <iostream>
#include <limits>  // Necessário para cin.ignore()
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;

  // para corrigir a entrada das minas de mineração
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int i = 0; i < n; i++) {
    string mine;
    getline(cin, mine);
    int counter = 0;
    int opened = 0;
    for (char c : mine) {
      if (c == '.') {
        continue;
      }
      if (c == '<') {
        opened++;
      } else if (opened > 0) {
        opened--;
        counter++;
      }
    }
    cout << counter << endl;
  }
}