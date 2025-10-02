#include <iostream>
#include <vector>
using namespace std;

int main() {
  int a, b;
  while (cin >> a >> b) {
    vector<int> nums(10);
    for (int i = a; i <= b; i++) {
      int curr = i;
      while (curr > 0) {
        int num = curr % 10;
        curr /= 10;
        nums[num]++;
      }
    }
    for (int j = 0; j < 10; j++) {
      cout << nums[j] << " ";
    }
    cout << endl;
  }
  return 0;
}