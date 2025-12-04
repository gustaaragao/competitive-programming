#include <bits/stdc++.h>
using namespace std;
// Grafo Acíclico Dirigido (DAG)
// - Arestas = Dependências -> Ex.: Disciplinas e Pre-requisitos
// - Definição: É uma permutação dos vértices tal que 
// para toda aresta v -> u, v aparece antes de u.
// - Ordem de execução da DP
const int MAXN=1e5+10;
int n, color[MAXN];
vector<int> adj[MAXN]; deque<int> order;
void dfs(int v) {
    color[v] = 1;
    for (auto u : adj[v]) {
        if (color[u] == 0) dfs(u);
        if (color[u] == 1) { // Achou um ciclo
            cout << "IMPOSSIBLE!" << endl;
            exit(0); // Não é um DAG
        }
    }
    order.push_front(v);
    color[v] = 2;
}
void topoSort() {
    for (int v = 0; v < n; v++) {
        if (color[v] == 0) dfs(v);
    }
}