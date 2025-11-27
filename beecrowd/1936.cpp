#include <bits/stdc++.h>
// using namespace std;

int fat(int n) {
  if (n == 1 || n == 0) {
    return 1;
  }
  return fat(--n) * n;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int n;
  std::cin >> n;
  int counter = 0;
  int sum = 0;
  while (sum < n) {
    int i = 0;
    while (sum + fat(i + 1) <= n) {
      i++;
    }
    sum += fat(i);
    counter++;
  }
  std::cout << counter << "\n";
  return 0;
}