#include <bits/stdc++.h>
using namespace std;

// Grafo Acíclico Dirigido (DAG)
// - Arestas = Dependências -> Ex.: Disciplinas e Pre-requisitos
// - Definição: É uma permutação dos vértices tal que 
// para toda aresta v -> u, v aparece antes de u.
// - Ordem de execução da DP

const int MAXN=1e5+10;

int n, color[MAXN];
vector<int> adj[MAXN];
// Ideia 1: Usando DFS
deque<int> order;
bool dfs(int v) { // É possível fazer sem o bool
    color[v] = 1;
    for (auto u : adj[v]) {
        if (color[u] == 0) {
            // dfs(u)
            if (!dfs(u)) return false;
        } else if (color[u] == 1) {
            // exit(-1)
            return false; // Não é um DAG
        }
    }
    order.push_front(v);
    color[v] = 2; // Marcou o vértice como finalizado
    return true;
}
bool topoSort() {
    for (int v = 0; v < n; v++) {
        if (color[v] == 0) {
            if (!dfs(v)) return false;
        }
    }
    return true;
}
signed main() {
    if (topoSort()) {
        for (auto x : order) cout << x << " ";
    } else {
        cout << "Impossible";
    }
    cout << endl;
}