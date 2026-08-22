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

int n;
vector<int> adj[MAXN];

void dfs(int v, int p, int dist[MAXN]) {
    for (auto u : adj[v]) if (u != p) {
        dist[u] = dist[v] + 1;
        dfs(u, v, dist);
    }
}

void solve() {
    int dist[MAXN] = {0}, dist_a[MAXN] = {0}, dist_b[MAXN] = {0};

    cin >> n;
    for (int i = 0; i < n-1; i++) {
       int u, v; cin >> u >> v; u--,v--;
       adj[u].pb(v);
       adj[v].pb(u);
    }
    // Procurando o "a"
    dfs(0, -1, dist);
    int d = 0, a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] > d) {
            d = dist[i];
            a = i;
        }
    }

    memset(dist, 0, sizeof(dist));
    // Procurando o "b"
    dfs(a, -1, dist);
    d = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] > d) {
            d = dist[i];
            b = i;
        }
    }
    // Calculando dist_a e dist_b
    dfs(a, -1, dist_a);
    dfs(b, -1, dist_b);
    for (int i = 0; i < n; i++) {
        cout << max(dist_a[i], dist_b[i]) << " ";
    }
    cout << endl;
}

signed main() {
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}
