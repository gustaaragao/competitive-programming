#include <bits/stdc++.h>
using namespace std; 
#define pb push_back
const int MAXN = 1e5 + 10;
vector<int> adj[MAXN], comp;
bool vis[MAXN];
int n, m;

void dfs(int v) {
    vis[v] = true;
    comp.pb(v);
    for (auto u : adj[v]) if (!vis[u]) {
        dfs(u);
    }
}

signed main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    // Encontrar os componentes conexos (O(V + E))
    for (int v = 0; v < n; v++) {
        if (!vis[v]) {
            comp.clear();
            dfs(v);
            // Percorrendo no componente conexo
            cout << "Component: ";
            for (auto u : comp) {
                cout << u << " ";
            }
            cout << endl;
        }
    }
}
// https://cp-algorithms.com/graph/search-for-connected-components.html