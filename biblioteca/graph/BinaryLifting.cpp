#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
const int LOG = 20; // 2^20 ~= 1e6
int n, q, parent[MAXN], up[MAXN][LOG];
vector<int> adj[MAXN];
void binary_lifting() { // O(nlog(n))
    // Calcula o primeiro ancestral
    for (int v = 0; v < n; v++)
        up[v][0] = parent[v];
    // Calcular o 2 até k-th ancestral
    for (int j = 1; j < LOG; j++)
        for (int v = 0; v < n; v++)
            if(up[v][j-1] == -1) 
                up[v][j] = -1; 
            else 
                up[v][j] = up[ up[v][j-1] ][j-1];
}
int kth_ancestor(int v, int k) { // O(log(n))
    for (int j = 0; j < LOG; j++) {
        if (v == -1) break;
        if (k & (1LL << j)) v = up[v][j];
    }
    return v;
}
void solve() {
    memset(parent, -1, sizeof(parent));
    cin >> n >> q;
    for (int v = 1; v < n; v++) {
        int u; cin >> u; u--;
        adj[v].pb(u);
        adj[u].pb(v);
        parent[v] = u;
    }
    binary_lifting();
    // Responder as queries
    for (int i = 0; i < q; i++) {
        int x, k; cin >> x >> k; x--;
        int ans = kth_ancestor(x, k);
        if (ans == -1) cout << ans;
        else cout << ans+1;
        cout << endl;
    }
    
}
