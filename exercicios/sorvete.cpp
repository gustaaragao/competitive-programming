#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define int long long 

typedef pair<int, int> pi;

const int INF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 2e5 + 10;

int n, m, x;
vector<pi> adj[MAX];
bool vis[MAX];
int dist_ufmg[MAX], dist_sorv[MAX];

void dijkstra(int s, int (&dist)[MAX]) {
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

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c; a--, b--;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }
    vector<int> amigos(x);
    for (int i = 0; i < x; i++) {
        int id; cin >> id; id--;
        amigos[i] = id;
    }
    // custo do amigo X = dist da UFMG para X + dist de Sorveteria para X
    //                  = dist_ufmg[x] + dist_sorv[x] -> O grafo é não direcionado.
    dijkstra(0, dist_ufmg);
    dijkstra(n-1, dist_sorv);
    int ans = INF;
    for (auto id : amigos) {
        ans = min(ans, dist_ufmg[id] + dist_sorv[id]);
    }
    cout << ans << endl;
}