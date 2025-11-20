#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool hasCycleBfs(int n, vector<vector<int>>& adj, vector<int>& indegree) {
  queue<int> q;
  int visitedCount = 0;

  for (int i = 1; i <= n; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    visitedCount++;

    for (int v : adj[u]) {
      indegree[v]--;
      if (indegree[v] == 0) {
        q.push(v);
      }
    }
  }

  return visitedCount != n;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  if (cin >> t) {
    while (t--) {
      int n, m;
      cin >> n >> m;

      vector<vector<int>> adj(n + 1);
      vector<int> indegree(n + 1, 0);

      for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
      }

      if (hasCycleBfs(n, adj, indegree)) {
        cout << "SIM\n";
      } else {
        cout << "NAO\n";
      }
    }
  }
  return 0;
}