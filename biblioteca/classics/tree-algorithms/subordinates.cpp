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

int n, sz[MAXN];
// bool vis[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int p) {
    sz[v] = 1;
    // vis[v] = true;
    for (auto u : adj[v]) if (u != p) {
        dfs(u, v);
        sz[v] += sz[u];
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
       int v; cin >> v; v--;
       adj[i].pb(v);
       adj[v].pb(i);
    }
    dfs(0, -1);
    for (int i = 0; i < n; i++) {
        cout << (sz[i]-1) << " ";
    }
    cout << endl;
}

signed main() {
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}
