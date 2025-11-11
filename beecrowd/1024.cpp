#include <algorithm>  // Para swap
#include <cctype>     // Para isalpha
#include <iostream>
#include <limits>  // Para numeric_limits
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;

  // Limpa o '\n' deixado pelo cin >> n
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  while (n--) {
    string text;
    getline(cin, text);

    for (int i = 0; i < text.length(); i++) {
      if (isalpha(text[i])) {  // Verifica se é letra
        text[i] += 3;
      }
    }

    reverse(text.begin(), text.end());

    int meio = text.length() / 2;
    for (int i = meio; i < text.length(); i++) {
      text[i] -= 1;
    }

    cout << text << "\n";
  }
  return 0;
}