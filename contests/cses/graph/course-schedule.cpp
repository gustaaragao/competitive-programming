#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define sz(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << x << endl

const int MAXN = 1e5 + 10;

int n, m;
vector<int> adj[MAXN], color(MAXN, 0); 
deque<int> order;;

void dfs(int v) {
    color[v] = 1;
    for (auto u : adj[v]) {
        if (color[u] == 0) dfs(u);
        if (color[u] == 1) {
            cout << "IMPOSSIBLE" << endl;
            exit(0);
        }
    }
    order.push_front(v);
    color[v] = 2;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v);
    }
    for (int v = 0; v < n; v++) {
        if (color[v] == 0) dfs(v);
    }
    for (int i = 0; i < n; i++) 
        cout << order[i] + 1 << " ";
    cout << endl;
}