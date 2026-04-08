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

vector<pi> bridges;
vector<int> adj[MAXN];
int n, m, dp[MAXN], lvl[MAXN], parent[MAXN], sz[MAXN];

void dfs(int v) {
    dp[v] = 0;
    sz[v] = 1;
    for (auto u : adj[v]) {
        if (u == parent[v]) continue;
        if (lvl[u] == 0) {
            parent[u] = v;
            lvl[u] = lvl[v] + 1;
            dfs(u);
            dp[v] += dp[u];
            sz[v] += sz[u];
        } else if (lvl[u] > lvl[v]) {
            dp[v]--;
        } else if (lvl[u] < lvl[v]) {
            dp[v]++;
        }
    }

    if (parent[v] != -1 and dp[v] == 0) {
        // Encontrou uma ponte
        bridges.pb({parent[v], v});
    }
}

void find_bridges() {
    memset(dp, 0, sizeof(dp));
    memset(sz, 0, sizeof(sz));
    memset(lvl, 0, sizeof(lvl));
    memset(parent, -1, sizeof(parent));

    dfs(0);
}

int comb2(int x) {
    return (x *(x - 1)) / 2;
}

void solve() {
   cin >> n >> m;
   for (int i = 0; i < m; i++) {
       int u, v; cin >> u >> v; u--, v--;
       adj[u].pb(v);
       adj[v].pb(u);
   }
   find_bridges();
   int ans = LLONG_MAX;
   for (auto [u, v] : bridges) {
        ans = min(ans, comb2(sz[0] - sz[u]) + comb2(sz[v]));
   }
   cout << ans << endl;
}

/*
Todo grafo G pode ser entendido como um conjunto de arestas de corte (pontes) e de SCCs (Componentes Fortemente Conexas).

Remover arestas dos SCCs não alteram a quantidade de vértice u e v que possuem um caminho.

Uma aresta ponte sempre dois SCCs.

Em todo SCC com v vértices temos (v 2) pares de vértices alcançáveis.

A partir da DFS Tree, podemos calcular v = sz[u], onde sz[u] é o tamanho da sub-árvore enraizada em u.

r - SCC_1 - u - v - SCC_2 (onde u - v é ponte)

Vamos fazer a DFS Tree a partir de r.

A solução do problema é dada por:

min (sz[r] - sz[u] 2) + (sz[v] 2)
*/

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc = 1;
    cin >> tc; 
    while(tc--) solve();
}
