#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Estados para a DFS
const int BRANCO = 0;
const int CINZA = 1;
const int PRETO = 2;

// Variáveis globais para evitar realocação excessiva
vector<vector<int>> adj;
vector<int> visited;

bool temCiclo(int u) {
  visited[u] = CINZA;  // Marca como "sendo visitado"

  for (int v : adj[u]) {
    if (visited[v] == CINZA) {
      return true;  // Achou um nó que já está na pilha de recursão -> CICLO!
    }
    if (visited[v] == BRANCO) {
      if (temCiclo(v)) return true;
    }
  }

  visited[u] = PRETO;  // Marca como "finalizado"
  return false;
}

int main() {
  // Otimização de I/O (Essencial para C++ no Beecrowd)
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    // Limpa e redimensiona as estruturas
    adj.assign(n + 1, vector<int>());
    visited.assign(n + 1, BRANCO);

    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);  // Cria a aresta u -> v
    }

    bool loop = false;
    // Precisamos iterar por todos os nós, pois o grafo pode ser desconexo
    for (int i = 1; i <= n; i++) {
      if (visited[i] == BRANCO) {
        if (temCiclo(i)) {
          loop = true;
          break;
        }
      }
    }

    cout << (loop ? "SIM" : "NAO") << "\n";
  }

  return 0;
}