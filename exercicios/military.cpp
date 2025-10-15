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

const int MAXN = 2e5 + 10;

int n, q;
vector<int> adj[MAXN], path;
bool vis[MAXN];

void dfs(int v) {
    vis[v] = true;
    path.pb(v);
    for (auto u : adj[v]) if(!vis[u]) {
        dfs(u);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> q;
    for (int v = 2; v <= n; v++) {
        int u; cin >> u;
        adj[u-1].pb(v-1);
    }

    for (int v = 0; v < n; v++)
        sort(all(adj[v]));
    
    for (int i = 0; i < q; i++) {
        int u, k; cin >> u >> k;
        u--; k--;
        path.clear();
        fill(vis, vis+MAXN, false);
        dfs(u);
        if ((k+1) <= sz(path)) {
            cout << (path[k]+1) << endl;
        } else {
            cout << -1 << endl;
        }
    }
}