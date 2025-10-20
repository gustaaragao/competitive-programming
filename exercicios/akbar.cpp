#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define sz(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pi;

const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAXN = 1e6 + 10;

int n, r, m;
vector<int> adj[MAXN];
bool vis[MAXN];
int cnt[MAXN];

void bfs(int k, int s) {
    queue<pi> q;
    vis[k] = true;
    cnt[k]++;
    q.push({k, 0});
    while(!q.empty()) {
        auto [v, d] = q.front(); q.pop();
        if (d == s) continue;
        for (auto u : adj[v]) if (!vis[u]) {
            q.push({u, d+1});
            vis[u] = true;
            cnt[u]++;
        }
    }
}

void solve() {
    cin >> n >> r >> m;
    memset(vis, false, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) adj[i].clear();
    // Resolvendo o problema:
    for (int i = 0; i < r; i++) {
        int u, v; cin >> u >> v; 
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i = 0; i < m; i++) {
        int k, s; cin >> k >> s; k--;
        bfs(k, s);
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (cnt[i] != 1) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t0; cin >> t0;
    while (t0--) solve();
}