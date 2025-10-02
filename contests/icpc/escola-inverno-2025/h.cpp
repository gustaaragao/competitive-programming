#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int ,int> pi;

#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << x << endl

template <class T>
using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = 16 + 1;

int n, m;
vector<int> adj[MAXN]; 
vector<vector<int>> paths;
ll fact[MAXN];

void dfs(int v, vector<int> &p) {
    if (adj[v].empty()) {
        paths.pb(p);
        return;
    }
    for (auto u : adj[v]) {
        p.pb(u);
        dfs(u, p);
        p.pop_back();
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) fact[i] = i * fact[i-1];
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
    }
    // Obter os caminhos que levam para um sumidouro
    vector<int> p = {0};
    dfs(0, p);

    // Fazer a contagem de permutações
    ll ans = 0;
    for (int i = 0; i < paths.size(); i++) {
        int path_size = paths[i].size();
        ans += fact[n - path_size + 1];
    }
    cout << ans << endl;
}