#include <bits/stdc++.h>
// using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int a, b;
  std::cin >> a >> b;

  std::vector<std::vector<char>> earth(a, std::vector<char>(b));
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      std::cin >> earth[i][j];
    }
  }
  int counter = 0;
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      if (earth[i][j] == '.') {
        continue;
      }

      char up = '.';
      if (i - 1 >= 0) {
        up = earth[i - 1][j];
      }
      if (up == '.') {
        counter++;
        continue;
      }

      char down = '.';
      if (i + 1 < a) {
        down = earth[i + 1][j];
      }
      if (down == '.') {
        counter++;
        continue;
      }

      char left = '.';
      if (j - 1 >= 0) {
        left = earth[i][j - 1];
      }
      if (left == '.') {
        counter++;
        continue;
      }

      char right = '.';
      if (j + 1 < b) {
        right = earth[i][j + 1];
      }
      if (right == '.') {
        counter++;
        continue;
      }
    }
  }

  std::cout << counter << "\n";

  return 0;
}