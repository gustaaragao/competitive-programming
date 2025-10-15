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

typedef long long ll;
typedef pair<int, int> pi;

const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAXN = 2e5 + 10;

vector<int> adj[MAXN];
int n, m;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    // Guloso:
    // Encontre o vértice com o menor grau
    // Coloque policiais em todos vértices exceto o de menor grau e seus vizinhos
    vector<int> ans(n, 1);
    // Passo 1: Encontrar o vértice com menor grau
    int min_deg = INF, min_v = -1;
    for (int v = 0; v < n; v++) {
        if (sz(adj[v]) < min_deg) {
            min_deg = sz(adj[v]);
            min_v = v;
        }
    }
    ans[min_v] = 0;
    for (auto u : adj[min_v]) ans[u] = 0;

    for (auto u : ans) cout << u << " ";
    cout << endl;
}