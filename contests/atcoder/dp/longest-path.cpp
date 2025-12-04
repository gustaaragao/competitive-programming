#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << x << endl

const int MAXN = 1e5 + 10;

int n, m;
deque<int> order;
vector<int> adj[MAXN], color(MAXN), dp(MAXN);

void dfs(int v) {
    color[v] = 1;
    for (auto u : adj[v]) {
        if (color[u] == 0) dfs(u);
        if (color[u] == 1) exit(-1); // Não é um DAG
    }
    order.push_front(v);
    color[v] = 2;
}
void topoSort() {
    for (int v = 0; v < n; v++) {
        if (color[v] == 0) dfs(v);
    }
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v);
    }
    topoSort();
    // PUSH DP
    // Para todo vértice v da ordenação topológica
    for (auto v : order) {
        // Para todo vizinho u de v
        for (auto u : adj[v]) {
            dp[u] = max(dp[u], dp[v] + 1);
        }
    }    
    int ans = 0LL;
    for (int v = 0; v < n; v++) ans = max(ans, dp[v]);
    cout << ans << endl;
}
