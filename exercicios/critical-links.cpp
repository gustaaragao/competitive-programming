#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
// #define int long long
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
// const int MAXN = 2e5+5;

int n;
vector<pi> ans;
vector<vector<int>> adj;
vector<int> dp, lvl, parent;

void dfs(int v) {
    dp[v] = 0;
    for (auto u : adj[v]) {
        if (u == parent[v]) continue;
        if (lvl[u] == 0) {
            parent[u] = v;
            lvl[u] = lvl[v]+1;
            dfs(u);
            dp[v] += dp[u];
        } else if (lvl[u] < lvl[v]) {
            dp[v]++;
        } else if (lvl[u] > lvl[v]) {
            dp[v]--;
        }
    }
    
    if (parent[v] != -1 and dp[v] == 0) {
        ans.pb({min(v, parent[v]), max(v, parent[v])});
    }
}

void solve() {
    while (cin >> n) {        
        adj = vector<vector<int>>(n);
        dp = vector<int>(n, 0);
        lvl = vector<int>(n, 0);
        parent = vector<int>(n, -1);            
        ans.clear();

        for (int i = 0; i < n; i++) {
            int v; cin >> v;
            char c; int x; cin >> c >> x >> c;
            for (int j = 0; j < x; j++) {
                int u; cin >> u;
                adj[v].pb(u);
            }
        }
        
        
        for (int v = 0; v < n; v++) {
            if (lvl[v] == 0) {
                lvl[v] = 1;
                dfs(v);
            }
        }
        
        sort(all(ans));
        cout << (int) ans.size() << " critical links" << endl;
        for (auto [u, v] : ans) {
            cout << u << " - " << v << endl;;
        }
        cout << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc = 1;
    //cin >> tc; 
    while(tc--) solve();
}
