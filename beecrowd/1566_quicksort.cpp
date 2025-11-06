#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int nums[], int j, int n) {
    int pivo = nums[n];
    int ptr = j;
    for (int i = j; i < n; i++) {
        if (nums[n] > nums[i])
            swap(nums[i], nums[ptr++]);
    }
    swap(nums[n], nums[ptr++]);
    return ptr;
}

void quickSort(int nums[], int start, int stop) {
    if (stop > start){
        int pivoIndex = partition(nums, start, stop);
        quickSort(nums, start, pivoIndex - 1);
        quickSort(nums, pivoIndex + 1, stop);
    }
}

int main() {
  // --- OTIMIZAÇÃO 1: I/O Rápido ---
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int testcases;
  cin >> testcases;

  while (testcases--) {
    int people;
    cin >> people;
    int* height = new int[people];
    for (int i = 0; i < people; i++) {
      cin >> height[i];
    }

    quickSort(height, 0, people);

    if (people > 0) {
      cout << height[0];
      for (int i = 1; i < people; i++) {
        cout << " " << height[i];
      }
    }
    cout << "\n";
  }
  return 0;
}