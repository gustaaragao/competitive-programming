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

#define int long long

const int INF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5 + 10;

int n, m, a, b;
vector<vector<int>> adj(MAX), adj_reverse(MAX);
vector<int> dist_0(MAX, -1), dist_a(MAX, -1), dist_b(MAX, -1);
bool vis[MAX];

void bfs(int s, const vector<vector<int>> &g, vector<int> &dist) {
    queue<int> q; q.push(s); 
    vis[s] = true;
    dist[s] = 0;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (auto u : g[v]) if (!vis[u]) {
            q.push(u); 
            vis[u] = true;
            dist[u] = dist[v] + 1;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m >> a >> b;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].pb(y); // y depende de x
        adj_reverse[y].pb(x);
    }
    // Considere G' o grafo G' invertido
    // ans = min(ans, dist de 0 até u em G + dist de a até u em G' + dist de b até u G')
    bfs(0, adj, dist_0);
    memset(vis, false, sizeof(vis));
    bfs(a, adj_reverse, dist_a);
    memset(vis, false, sizeof(vis));
    bfs(b, adj_reverse, dist_b);
    int ans = INF;
    for (int u = 0; u <= n; u++) {
        if ((dist_0[u] != -1) and (dist_a[u] != -1) and (dist_b[u] != -1)) {
            ans = min(ans, dist_0[u] + dist_a[u] + dist_b[u]);
        }
    }
    cout << ans << endl;
}
/*
https://codeforces.com/blog/entry/48119#comment-323957
Do 3 BFSes. Let G be the graph formed by the dependencies and G' be the same graph, with all its edge inverted. (changed direction)

Now, note that each correct labelling must "meet" at some point u (This may include 0, a or b), so the answer is the minimum possible value of this over all possible u :

Distance from 0 to u in G + Distance from a to u in G' + Distance from b to u in G'.
*/