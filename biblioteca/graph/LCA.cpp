#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+5;
const int LOG = 20;
int n, q, up[MAXN][LOG], depth[MAXN];
vector<int> adj[MAXN];
void dfs(int v, int p) { // O(nlog(n))
    for (auto u : adj[v]) if (u != p) {
        depth[u] = depth[v] + 1;
        up[u][0] = v;
        for (int j = 1; j < LOG; j++) {
            up[u][j] = up[ up[u][j-1] ][j-1];
        }
        dfs(u, v);
    }
}
// Binary Lifting -> Encontrar o kth ancestor O(logn)
int get_kth(int x, int k) {
    if (k > depth[x]) return -1;
    for (int i = 0; i < LOG; i++) {
        if (k & (1 << i))
            x = up[x][i];
    }
    return x;
}
// Encontrar o LCA O(log(n))
int get_lca(int a, int b) {
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    int k = depth[a] - depth[b];
    for (int j = LOG-1; j >= 0; j--) {
        if (k & (1 << j)) {
            a = up[a][j];
        }
    }
    if (a == b) {
        return a;
    }
    for (int j = LOG-1; j >= 0; j--) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}
void solve() {
    cin >> n >> q;
    for (int v = 1; v < n; v++) {
        int u; cin >> u; u--;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    dfs(0, -1);
    for (int i = 0; i < q; i++) {
        // int a, b; cin >> a >> b; a--, b--;
        // cout << (get_lca(a, b) + 1) << endl;
        int x, k; cin >> x >> k; x--;
        int ans = get_kth(x, k);
        if (ans == -1) cout << ans;
        else cout << ans+1;
        cout << endl;
    }
}
