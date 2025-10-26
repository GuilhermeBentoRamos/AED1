#include <iostream>

using namespace std;

void merge(int start, int half, int stop, int nums[]) {
  int ptr1 = start, ptr2 = half, i = 0;
  int* merged = new int[stop - start];
  while (ptr1 < half && ptr2 < stop) {
    if (nums[ptr1] < nums[ptr2])
      merged[i++] = nums[ptr1++];
    else
      merged[i++] = nums[ptr2++];
  }
  while (ptr1 < half)
    merged[i++] = nums[ptr1++];
  while (ptr2 < stop)
    merged[i++] = nums[ptr2++];

  for (i = start; i < stop; i++)
    nums[i] = merged[i - start];
  delete[] merged;
}

void mergeSort(int start, int stop, int nums[]) {
  if (stop - start > 1) {
    int half = start + (stop - start) / 2;
    mergeSort(start, half, nums);
    mergeSort(half, stop, nums);
    merge(start, half, stop, nums);
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

    mergeSort(0, people, height);

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