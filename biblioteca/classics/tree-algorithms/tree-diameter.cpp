#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define int long long
#define endl '\n' // << flush
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << x << endl
#define uniq(x) sort(all(x)); v.erase(unique(all(x)), x.end())
typedef pair<int, int> pi;
typedef long long ll;

// const int MOD = 1e9 + 7; // 998244353
// const int INF = 0x3f3f3f3f;
// const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 2e5 + 5;

int n, dist[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int p) {
    for (auto u : adj[v]) if (u != p) {
        dist[u] = dist[v] + 1;
        dfs(u, v);
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
       int u, v; cin >> u >> v; u--,v--;
       adj[u].pb(v);
       adj[v].pb(u);
    }

    dfs(0, -1);
    int d = 0, a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] > d) {
            d = dist[i];
            a = i;
        }
    }

    memset(dist, 0, sizeof(dist));

    dfs(a, -1);
    d = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] > d) {
            d = dist[i];
            b = i;
        }
    }

    cout << d << endl;
}

signed main() {
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}
