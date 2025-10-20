#include <bits/stdc++.h>
using namespace std; 
#define pb push_back
#define MAXN 100005
vector<int> adj[MAXN];
bool visited[MAXN];
int n, m;
// O(v + E)
void dfs(int v) { // dfs(int v, int p=-1) -> Árvores
    visited[v] = true;
    // for (auto u : adj[v]) if (u != p) { -> Árvores
    for (auto u : adj[v]) if (!visited[u]) {
        dfs(u);
    }
}
// https://cp-algorithms.com/graph/depth-first-search.html