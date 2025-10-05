#include <bits/stdc++.h>
using namespace std; 
#define pb push_back
#define MAXN 100005
vector<int> adj[MAXN];
bool visited[MAXN];
int n, m;
// O(v + E)
void dfs(int v) {
    visited[v] = true;
    for (auto u : adj[v]) {
        if (!visited[u]) {
            dfs(u);
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