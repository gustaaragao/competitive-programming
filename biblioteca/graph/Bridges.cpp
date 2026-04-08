#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
vector<pair<int, int>> ans;
// dp[u] -> qtd de back-edges que passam por cima da aresta (parent[u], u)
// lvl[u] -> nível do vértice u
int n, dp[MAXN], lvl[MAXN], parent[MAXN];
void dfs(int v) {
    dp[v] = 0;
    for (auto u : adj[v]) {
        if (u == parent[v]) continue;
        if (lvl[u] == 0) { 
            parent[u] = v;
            lvl[u] = lvl[v]+1;
            dfs(u);
            dp[v] += dp[u];
        } else if (lvl[u] < lvl[v]) { // aresta acima
            dp[v]++;
        } else if (lvl[u] > lvl[v]) { // aresta abaixo
            dp[v]--;
        }
    }

    if (parent[v] != -1 and dp[v] == 0) {
        // Encontrou uma ponte
        ans.pb({min(v, parent[v]), max(v, parent[v])});
    }
}
void find_bridges() {
    memset(parent, -1, sizeof(parent));
    for (int v = 0; v < n; v++) {
        if (lvl[v] == 0) {
            lvl[v] = 1; // marca como visitado
            dfs(v);
        }
    }
}
// https://onlinejudge.org/external/7/796.pdf
/*
Ponte é uma aresta que caso seja removida transforma o grafo em desconexo
- Back-edge é uma aresta (u, v) que conecta u (pai) com v (descendente de u).
- Span-edge é uma aresta (u, v) marcada na DFS, representa uma DFS Tree do Grafo G.
# Observações
1) Uma span-edge (u, v) é uma ponte <-> não existe nenuma back-edge que conecta algum ancestral de uv
                                        com algum descendente de uv.
                                    <-> não existe um back-edge que "atravessa por alto" uv.
2) A back-edge não é nunca ponte.
# Algoritmo:
Dado um grafo G:
1) Construa a DFS Tree de G
2) Para toda span-edge (u, v), caso não existe nenhuma back-edge que "atravessa por alto" (u, v), 
                               (u, v) é uma ponte.
*/
