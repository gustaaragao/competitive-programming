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
// o caminho encontrado do BFS é o MENOR CAMINHO em um grafo não-ponderado
void bfs(int s) { // s -> vértice inicial
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        if (visited[v]) continue;
        visited[v] = true;
        for (auto const &u : adj[v]) {
            // visitando os filhos de v
            if (!visited[u]) q.push(u);
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
    bfs(0);
}
// https://cp-algorithms.com/graph/breadth-first-search.html