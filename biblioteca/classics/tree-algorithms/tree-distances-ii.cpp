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
int n, sub[MAXN],  ans[MAXN];

void dfs1(int v, int p, int depth) {
    sub[v] = 1;
    ans[0] += depth;
    for (auto u : adj[v]) if (u != p) {
        dfs1(u, v, depth+1);
        sub[v] += sub[u];
    }
}

void dfs2(int v, int p) {
    for (auto u : adj[v]) if (u != p) {
        ans[u] = ans[v] + (n - 2*sub[u]);
        dfs2(u, v);
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    dfs1(0, -1, 0);
    dfs2(0, -1);
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc = 1;
    // cin >> tc;
    while(tc--) solve();
}
