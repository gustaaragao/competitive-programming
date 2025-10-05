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
#define dbg(x) cout << #x << ' = ' << x << endl

template <class T>
using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = 1e3 + 10;

int n, m;
vector<int> adj[MAXN];
bool visited[MAXN];

void dfs(int v) {
    visited[v] = true;
    for (auto u : adj[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            ans++;
        }
    }
    cout << ans << endl;
}