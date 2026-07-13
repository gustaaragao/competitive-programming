#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define int long long
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pi;
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 1e3 + 5;

vector<int> adj[MAXN], va, vb;
int n, m, na, nb, color[MAXN], idA[MAXN], idB[MAXN];

bool dfs(int v) {
    for (auto u : adj[v]) {
        if (color[u] == -1) {
            color[u] = (color[v] == 1) ? 2 : 1;
            if (!dfs(u)) return false;
        } else if (color[u] == color[v]) {
            return false;
        }
    }
    return true;
}

struct kuhn {
    int n,m;
    vector<vector<int>> adj;
    vector<int> ma, mb;
    vector<bool> vis;
    kuhn(int n_, int m_) : n(n_), m(m_), adj(n),
        vis(n+m), ma(n, -1), mb(m, -1) {}
    void add(int a, int b) {adj[a].pb(b);}
    bool dfs(int v) {
        vis[v] = true;
        for (auto u : adj[v]) if(!vis[u+n]) {
            vis[u+n] = true;
            if (mb[u] == -1 or dfs(mb[u])) {
                ma[v] = u, mb[u] = v;
                return true;
            }
        }
        return false;
    }
    int matching() {
        int ret = 0;
        for (auto &x : adj) shuffle(all(x), rng);
        bool aum = true;
        while (aum) {
            for (int u = 0; u < m; u++) vis[u+n] = 0;
            aum = false;
            for (int v = 0; v < n; v++)
                if (ma[v] == -1 and dfs(v)) ret++, aum = true;
        }
        return ret;
    }
};

void solve() {
    cin >> n >> m;

    na = nb = 0;
    va.clear(), vb.clear();
    for (int i = 0; i < n; i++) color[i] = -1;
    for (int i = 0; i < n; i++) adj[i].clear();
    
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    // o grafo G tem apenas ciclos pares sse G é bipartido
    bool valid = true;
    for (int v = 0; v < n; v++) {
        if (color[v] == -1) {
            color[v] = 1;
            if (!dfs(v)) {
                valid = false;
                break;
            }
        }
    }
    if (valid) {
        for (int v = 0; v < n; v++) {
            if (color[v] == 1) {
                idA[v] = na;
                na++;
                va.pb(v);
            } else {
                idB[v] = nb;
                nb++;
                vb.pb(v);
            }
        }
    } else {
        throw runtime_error("re");
    }
    kuhn k(na, nb);
    for (auto a : va) {
        for (auto b : adj[a]) {
            k.add(idA[a], idB[b]); // mapeia para 0-indexed
        }
    }
    // cobertura mínima por arestas = qtd de vértices - emparelhamento máximo
    cout << n - k.matching() << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc;
    while (tc--) solve();
}