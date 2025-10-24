#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define eb emplace_back
#define int long long

typedef pair<int, int> pi;

const int MAX = 1e5 + 10;
const int INF = 0x3f3f3f3f3f3f3f3fll;

int n, m;
vector<pi> adj[MAX];
bool vis[MAX]; int dist[MAX];

void dijkstra(int s) {
    fill(vis, vis+MAX, false);
    fill(dist, dist+MAX, INF);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, s}); dist[s] = 0;
    while (!pq.empty()) {
        auto [d, v] = pq.top(); pq.pop();
        if (vis[v]) continue;
        vis[v] = true;
        for (auto [u, w] : adj[v]) if (dist[u] > dist[v] + w) {
            dist[u] = dist[v] + w;
            pq.push({dist[u], u});
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c; a--, b--;
        adj[a].pb({b, c});
    }
    int x, y; cin >> x >> y; x--, y--;
    dijkstra(x);
    if (dist[y] == INF) {
        cout << "NO" << endl;
    } else {
        cout << dist[y] << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t0; cin >> t0;
    while (t0--) solve();
}