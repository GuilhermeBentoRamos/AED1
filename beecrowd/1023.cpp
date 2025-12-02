#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n, i = 1;
  bool first = true;

  while (std::cin >> n && n != 0) {
    if (!first) std::cout << "\n";
    first = false;

    std::cout << "Cidade# " << i++ << ":\n";

    std::map<int, int> usage;
    int total_sum = 0;
    int total_people = 0;

    for (int j = 0; j < n; j++) {
      int a, b;
      std::cin >> a >> b;
      total_people += a;
      total_sum += b;
      usage[b / a] += a;
    }

    auto it = usage.begin();
    while (it != usage.end()) {
      std::cout << it->second << "-" << it->first;
      it++;
      if (it != usage.end()) std::cout << " ";
    }

    double media = (double)total_sum / total_people;
    double media_trunc = floor(media * 100.0) / 100.0;

    std::cout << "\nConsumo medio: " << std::fixed << std::setprecision(2)
              << media_trunc << " m3.\n";
  }

  return 0;
}