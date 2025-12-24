#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

/*
LCA ~ tamanho das subtrees em i (sz[i])

Se sz[i] >= k, então podemos escolher k-1 nós da subárvore além do i, logo o LCA = i
*/

const int MAXN = 2e5 + 10;

vector<int> adj[MAXN], sz;

void dfs(int v, int p) {
    for (auto u : adj[v]) if (u != p) {
        dfs(u, v);
        sz[v] += sz[u];
    }
}

void solve() {
    int n, k; cin >> n >> k;
    fill(adj, adj+n, vector<int>());
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    sz = vector<int>(n+1, 1);
    dfs(0, -1);
    
    // for (int i = 0; i < n; i++) {
    //     cout << sz[i] << " ";
    // }
    // cout << endl;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        // Quantas vezes o nó i pode ser LCA
        if (sz[i] >= k) {
            // Podemos fixar uma raiz r FORA da subarvore i
            ans += n - sz[i]; // o i aparece em quantos Sr?
        }
        if (n - sz[i] >= k) {
            // Podemos fixar uma raiz r DENTRO da subarvore i
            ans += sz[i];
        }
    }
    // Caso trivial: Para toda raiz r podemos tomar LCA(r, "k-1 outros nós") = r
    ans += n;
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc; while (tc--) solve();
}
