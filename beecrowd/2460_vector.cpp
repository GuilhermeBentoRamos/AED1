#include <iostream>
#include <vector>
using namespace std;

int main () {
    // Desabilita sincronização para I/O rápido
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> queue(n);
    
    // Encontra o maior ID para saber o tamanho do vetor de marcação
    int max_id = 0; 
    for (int i = 0; i < n; i++) {
        cin >> queue[i];
        if (queue[i] > max_id) {
            max_id = queue[i];
        }
    }

    int m;
    cin >> m;
    
    vector<bool> removed(max_id + 1, false); 

    while (m--) {
        int x;
        cin >> x;
        if (x <= max_id) {
            removed[x] = true;
        }
    }

    bool firstElement = true; // Para controlar o espaço

    for (int i = 0; i < n; i++) {
        int id = queue[i];
        
        if (!removed[id]) { 
            if (firstElement) {
                cout << id;
                firstElement = false;
            } else {
                cout << " " << id;
            }
        }
    }
    
    cout << "\n";
    return 0;
}