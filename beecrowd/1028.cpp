#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (a < b) {
      int temp = a;
      a = b;
      b = temp;
    }
    while (a - b > 0) {
      a = a - b;
      if (a < b) {
        int temp = a;
        a = b;
        b = temp;
      }
    }
    cout << a << endl;
  }

  return 0;
}