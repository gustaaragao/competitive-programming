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

vector<int> adj[MAXN];
int n, q, timer = 0, dp[MAXN], tin[MAXN], tout[MAXN], a[MAXN];

struct fenw {
    int n;
    vector<int> bit;
    fenw() {}
    fenw(int size) {
        n = size;
        bit.assign(size + 1, 0);
    }
    // query do prefixo a[0] + a[1] + ... + a[r]
    int qry(int r) {
        int ans = 0;
        for (int i = r + 1; i > 0; i -= i & -i) // i & -i retorna os bits menos signativos de i 
            ans += bit[i];
        return ans;
    }
    // atualiza o valor a[r] = x
    void upd(int r, int x) {
        for (int i = r + 1; i <= n; i += i & -i) bit[i] += x;
    }
};

void dfs(int v, int p) {
    tin[v] = timer++;
    for (auto u : adj[v]) if (u != p) {
        dfs(u, v);
    }
    // o tout[v] é o tempo do último vértice da subárvore de v
    tout[v] = timer - 1;
}

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    // Podemos usar Euler Tour para processar uma árvore enraizada
    // como um array contínua (Fenwick, Seg, ...) -> Podemos fazer upd e range queries
    dfs(0, -1);
    // Para cada intervalo [tin[i], tout[i]], temos que todo subintervalo [tin[j], tout[j]]
    // temos que todos os vértices j pertencem a sub-árvore enraizada em i.
    fenw BIT(n);    
    for (int i = 0; i < n; i++) BIT.upd(tin[i], a[i]);
    for (int i = 0; i < q; i++) {
        int op; cin >> op;
        if (op == 1) {
            // atualiza o valor do vértice v
            int v, x; cin >> v >> x; v--;
            BIT.upd(tin[v], x - a[v]);
            a[v] = x;
        } else {
            // query na soma da subarvore de v
            // = soma do intervalo [tin[v], tout[v]]
            int v; cin >> v; v--;
            int end = BIT.qry(tout[v]);
            int start = (tin[v] == 0) ? 0 : BIT.qry(tin[v]-1);
            cout << (end - start) << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc = 1;
    //cin >> tc; 
    while(tc--) solve();
}
