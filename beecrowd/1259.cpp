#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> pares;
  vector<int> impares;
  int val;

  for (int i = 0; i < n; i++) {
    cin >> val;
    if (val % 2 == 0) {
      pares.push_back(val);
    } else {
      impares.push_back(val);
    }
  }

  sort(pares.begin(), pares.end());
  sort(impares.begin(), impares.end(), greater<int>());

  for (int i = 0; i < pares.size(); i++) {
    cout << pares[i] << endl;
  }

  for (int i = 0; i < impares.size(); i++) {
    cout << impares[i] << endl;
  }

  return 0;
}