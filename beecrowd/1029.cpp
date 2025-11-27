#include <iostream>
using namespace std;

int fib(int num, int& counter) {
  counter++;
  if (num == 1 || num == 0) {
    return num;
  }
  return fib(num - 1, counter) + fib(num - 2, counter);
}

int main() {
  int testcases;
  cin >> testcases;
  while (testcases--) {
    int counter = 0;
    int num;
    cin >> num;
    int result = fib(num, counter);
    cout << "fib(" << num << ") = " << --counter;
    cout << " calls = " << result << endl;
  }
  return 0;
}