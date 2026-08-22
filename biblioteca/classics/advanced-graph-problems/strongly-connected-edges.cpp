#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define int long long
#define endl '\n' //<< flush
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

vector<int> adj[MAXN];
vector<pi> span_edges, back_edges;
int n, m, bridges, lvl[MAXN], dp[MAXN], parent[MAXN];

void dfs(int v) {
    dp[v] = 0;
    for (auto u : adj[v]) {
        if (u == parent[v]) continue;
        if (lvl[u] == 0) {
            span_edges.pb({v, u});
            parent[u] = v;
            lvl[u] = lvl[v] + 1;
            dfs(u);
            dp[v] += dp[u];
        } else if (lvl[u] > lvl[v]) {
            back_edges.pb({u, v});
            dp[v]--;
        } else if (lvl[u] < lvl[v]) {
            dp[v]++;
        }
    }

    if (parent[v] != -1 and dp[v] == 0) {
        bridges++;
    }
}

void solve() {
    memset(parent, -1, sizeof(parent));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    lvl[0] = 1;
    dfs(0);
    bool ok = true;
    for (int v = 0; v < n; v++) {
        if (lvl[v] == 0) {
            ok = false;
            break;
        }
    }
    if (!ok or (bridges > 0)) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    // Todas as arestas da DFS Tree são direcionadas para baixo (pai -> filho)
    for (auto [u, v] : span_edges) {
        cout << u+1 << " " << v+1 << endl;
    }
    // Todas as back edges são direcionadas para cima (filho -> pai)
    for (auto [u, v] : back_edges) {
        cout << u+1 << " " << v+1 << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc = 1;
    //cin >> tc;
    while(tc--) solve();
}
