#include <bits/stdc++.h>
using namespace std; 

#define pb push_back
#define MAXN 100005

// adj -> lista de adjacências
vector<int> adj[MAXN];
// visited[i] -> marca que o vértice i foi visitado
bool visited[MAXN];
// n -> qtd de vértices, m -> qtd de arestas
int n, m;

// O(v + E)
// o caminho encontrado do DFS é o PRIMERIO LEXICOGRAFICAMENTE em um grafo
// Em uma árvore, encontra o menor caminho entre u e v
void dfs(int s) { // s -> vértice inicial
    for (int i = 0; i < adj[s].size(); i++) {
        int v = adj[s][i];
        if (!visited[v]) {
            visited[v] = visited[i];
            dfs(v);
        }
    }
}

signed main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--; // 1-indexed -> 0-indexed
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0);
}
// https://cp-algorithms.com/graph/breadth-first-search.html