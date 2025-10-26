#include <iostream>
#include <vector>
using namespace std;

// Nenhuma mudança na lógica de ordenação
void sort(int n, vector<int>& nums) {
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      minIndex = (nums[j] < nums[minIndex]) ? j : minIndex;
    }
    int temp = nums[i];
    nums[i] = nums[minIndex];
    nums[minIndex] = temp;
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
    vector<int> height(people);
    for (int i = 0; i < people; i++) {
      cin >> height[i];
    }

    sort(people, height);

    // --- OTIMIZAÇÃO 2: Loop de Impressão ---
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