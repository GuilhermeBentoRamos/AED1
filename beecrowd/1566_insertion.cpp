#include <iostream>
#include <vector>
using namespace std;

// Nenhuma mudança na lógica de ordenação
void sortInsert(int n, vector<int>& nums) {
  int j;
  for (int i = 1; i < n; i++) {
    int temp = nums[i];
    for (j = i - 1; j >= 0 && nums[j] > temp; j--) {
      nums[j + 1] = nums[j];
    }
    nums[j + 1] = temp;
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

    sortInsert(people, height);

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