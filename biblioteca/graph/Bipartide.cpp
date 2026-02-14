#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int MAXN = 2e5+5;

bool vis[MAXN];
int n, m, color[MAXN];
vector<int> adj[MAXN];

bool dfs(int v) {
    for (auto u : adj[v]) {
        if (color[u] == -1) {
            color[u] = (color[v] == 1) ? 2 : 1;
            if (!dfs(u)) return false;
        } else if (color[u] == color[v]) {
            return false; // conflito -> não bipartido
        }
    }
    return true;
}

signed main() {
    memset(color, -1, sizeof(color));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bool valid = true;
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            color[i] = 1;
            if (!dfs(i)) {
                valid = false;
                break;
            }
        }
    }

    if (valid) {
        for (int v = 0; v < n; v++) cout << color[v] << " ";
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}
