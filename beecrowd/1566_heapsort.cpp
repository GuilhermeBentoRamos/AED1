#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i;    
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);

        maxHeapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
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

    heapSort(height, people);

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