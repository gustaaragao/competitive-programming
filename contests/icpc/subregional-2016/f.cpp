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
const int MAXN = 1e4 + 10;

int n0, n1, sz[MAXN];
vector<int> adj0[MAXN], adj1[MAXN];
bool central0[MAXN], central1[MAXN];

void dfs(int v, int p, vector<int> adj[MAXN], bool central[MAXN]) {
    sz[v] = 1;
    for (auto u : adj[v]) if (u != p) {
        dfs(u, v, adj, central);
        sz[v] += (central[u] ? sz[u] : 0);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    // maximizar a qtd de vértices sobrepostos
    // n0 + n1 - qtd de vértices sobrepostos
    cin >> n0;
    for (int ii = 0; ii < n0; ii++) {
        int i, l, k; cin >> i >> l >> k; i--;
        if (l != 0) {
            l--;
            adj0[i].pb(l);
            adj0[l].pb(i);
        }
        if (k != 0) {
            k--;
            adj0[i].pb(k);
            adj0[k].pb(i);
            central0[k] = true;
        }
    }
    cin >> n1;
    for (int ii = 0; ii < n1; ii++) {
        int p, q, r; cin >> p >> q >> r; p--;
        if (q != 0) {
            q--;
            adj1[p].pb(q);
            adj1[q].pb(p);
            central1[q] = true;
        }
        if (r != 0) {
            r--;
            adj1[p].pb(r);
            adj1[r].pb(p);
        }
    }

    central0[0] = true, central1[0] = true;

    // min(maxima sequencia da esq, maxima sequencia da dir)
    dfs(0, -1, adj0, central0);
    int mx_esq = *max_element(sz, sz+n0);
    int root_esq = sz[0];

    dfs(0, -1, adj1, central1);
    int mx_dir = *max_element(sz, sz+n1);
    int root_dir = sz[0];
    
    // eu preciso sempre pegar a raiz de uma árvore
    // e encaixar no vértice u da outra árvore com a maior sequência
    int ans = max(min(mx_esq, root_dir), min(mx_dir, root_esq));

    cout << n0 + n1 - ans << endl;
}