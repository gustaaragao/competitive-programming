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
#define int long long int
const int MAXN = 1e5 + 10;
int n, m;
vector<int> adj[MAXN], dist(MAXN, -1), parent(MAXN, -1);
bool vis[MAXN];

void bfs(int s) {
    queue<int> q; 
    q.push(s); vis[s] = true; 
    dist[s] = 0;
    parent[s] = -1;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (auto u : adj[v]) if (!vis[u]) {
            q.push(u); vis[u] = true;
            dist[u] = dist[v] + 1;
            parent[u] = v;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; 
        u--; v--;
        adj[u].pb(v); 
        adj[v].pb(u);
    }
    bfs(0);
    if (!vis[n-1]) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        stack<int> path;
        int v = n-1;
        for (int i = 0; i <= dist[n-1]; i++) {
            path.push(v);
            v = parent[v];
        }
        cout << path.size() << endl;
        while (!path.empty()) {
            cout << path.top() + 1<< " ";
            path.pop();
        }
        cout << endl;
    }
}