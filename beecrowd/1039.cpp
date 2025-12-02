#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int a, b, c, d, e, f;
  while (std::cin >> a >> b >> c >> d >> e >> f) {
    double dist = sqrt(pow(e - b, 2) + pow(f - c, 2));

    if (a >= d + dist) {
      std::cout << "RICO\n";
    } else {
      std::cout << "MORTO\n";
    }
  }

  return 0;
}