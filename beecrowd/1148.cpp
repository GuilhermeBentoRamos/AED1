#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

int dijkstra(int n, vector<vector<int>>& graph, int src, int dest) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  vector<int> dist(n + 1, INF);
  dist[src] = 0;
  pq.push({0, src});
  while (!pq.empty()) {
    int d = pq.top().first;
    int u = pq.top().second;
    pq.pop();

    for (int v = 1; v <= n; v++) {
      if (graph[u][v] != INF) {
        if (graph[u][v] + d < dist[v]) {
          dist[v] = d + graph[u][v];
          pq.push({dist[v], v});
        }
      }
    }
  }
  return dist[dest];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int n, e;
  while (cin >> n >> e && n != 0) {
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
    for (int i = 0; i < e; i++) {
      int x, y, time;
      cin >> x >> y >> time;
      graph[x][y] = time;
      if (graph[y][x] != INF) {
        graph[x][y] = 0;
        graph[y][x] = 0;
      }
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
      int src, dest;
      cin >> src >> dest;
      int distance = dijkstra(n, graph, src, dest);
      if (distance == INF) {
        cout << "Nao e possivel entregar a carta\n";
      } else {
        cout << distance << "\n";
      }
    }
    cout << "\n";
  }

  return 0;
}