#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
// #define int long long
#define endl '\n' // << flush
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cerr << #x << " = " << x << endl
#define uniq(v) sort(all(v)); v.erase(unique(all(v)), v.end())
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef pair<int, int> pi;
// const int MOD = 1e9 + 7; // 998244353;
// const int INF = 0x3f3f3f3f;
// const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 2e5+5;
const int LOG = 20;

int n, q, up[MAXN][LOG], depth[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int p) {
    for (auto u : adj[v]) if (u != p) {
        depth[u] = depth[v] + 1;
        up[u][0] = v;
        for (int j = 1; j < LOG; j++) {
            up[u][j] = up[ up[u][j-1] ][j-1];
        }
        dfs(u, v);
    }
}

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
        int a, b; cin >> a >> b; a--, b--;
        cout << (get_lca(a, b) + 1) << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc = 1;
    //cin >> tc;
    while(tc--) solve();
}
