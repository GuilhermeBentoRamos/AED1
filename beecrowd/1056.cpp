#include <bits/stdc++.h>

std::vector<int> adj[105];
int match[105];
bool vis[105];

bool dfs(int u) {
  for (int v : adj[u]) {
    if (vis[v]) continue;
    vis[v] = true;
    if (match[v] < 0 || dfs(match[v])) {
      match[v] = u;
      return true;
    }
  }
  return false;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int t;
  std::cin >> t;
  for (int caseNum = 1; caseNum <= t; caseNum++) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];

    int m;
    std::cin >> m;
    std::vector<int> b(m);
    for (int i = 0; i < m; i++) std::cin >> b[i];

    for (int i = 0; i < n; i++) adj[i].clear();

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i] == 0) {
          if (b[j] == 0) adj[i].push_back(j);
        } else if (b[j] % a[i] == 0) {
          adj[i].push_back(j);
        }
      }
    }

    int result = 0;
    std::fill(match, match + m, -1);
    for (int i = 0; i < n; i++) {
      std::fill(vis, vis + m, false);
      if (dfs(i)) result++;
    }

    std::cout << "Case " << caseNum << ": " << result << "\n";
  }

  return 0;
}