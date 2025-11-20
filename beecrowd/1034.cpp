#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<int> blocks(n);
    for (int i = 0; i < n; i++) {
      cin >> blocks[i];
    }

    vector<int> dp(m + 1, 1000000000);
    dp[0] = 0;

    for (int i = 1; i <= m; i++) {
      for (int j = 0; j < n; j++) {
        if (i >= blocks[j]) {
          if (dp[i - blocks[j]] != 1000000000) {
            dp[i] = min(dp[i], dp[i - blocks[j]] + 1);
          }
        }
      }
    }

    cout << dp[m] << "\n";
  }

  return 0;
}