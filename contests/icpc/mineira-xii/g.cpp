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
typedef tuple<int, int, int> ti;
const int MOD = 1e9 + 7; // 998244353;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 5e5 + 10;

// dist[0] -> a pé no começo antes do uber
// dist[1] -> de carro
// dist[2] -> a pé no final depois do uber
int n, c, p, dist[3][MAXN];
vector<pi> adj_car[MAXN], adj_walk[MAXN];

// a ideia é fazer um dijkstra com 3 estados possíveis
// onde temos a seguinte máquina de estados
// 0 --> 1 --> 2 (Obs: posso me manter no mesmo estado)
void dijkstra(int s) {
    for (int i = 0; i < 3; i++) fill(dist[i], dist[i]+n, LINF);

    priority_queue<ti, vector<ti>, greater<ti>> pq;
    // começa no estado de pé antes do Uber (Estado 0)
    pq.push({0, s, 0}); dist[0][s] = 0;
    while (!pq.empty()) {
        auto [d, v, st] = pq.top(); pq.pop();

        if (d > dist[st][v]) continue;
        
        // Mudança de Estado
        // Se estou a pé no início (0), posso pegar o carro (1) no mesmo vértice
        if (st == 0 and dist[1][v] > d) {
            dist[1][v] = d;
            pq.push({d, v, 1});
        }
        // Se estou no carro (1), posso descer e ir pro a pé do final (2)
        if (st == 1 and dist[2][v] > d) {
            dist[2][v] = d;
            pq.push({d, v, 2});
        }

        // Estou à pé
        if (st == 0 or st == 2) {
            for (auto [u, w] : adj_walk[v]) if (dist[st][u] > d + w) {
                dist[st][u] = d + w;
                pq.push({dist[st][u], u, st});
            }
        } else if (st == 1) { // Estou de Uber
            for (auto [u, w] : adj_car[v]) if (dist[st][u] > d + w) {
                dist[st][u] = d + w;
                pq.push({dist[st][u], u, st});
            }
        }
    } 
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> c >> p;
    for (int i = 0; i < c; i++) {
        int a, b, w; cin >> a >> b >> w; a--, b--;
        adj_car[a].pb({b, w});
    }
    for (int i = 0; i < p; i++) {
        int a, b, w; cin >> a >> b >> w; a--, b--;
        adj_walk[a].pb({b, w});
        adj_walk[b].pb({a, w});
    }
    dijkstra(0);
    cout << min({dist[0][n-1], dist[1][n-1], dist[2][n-1]}) << endl;
}