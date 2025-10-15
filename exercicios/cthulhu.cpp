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

const int MAXN = 1e2 + 10;

int n, m;
vector<int> adj[MAXN];
bool vis[MAXN];

void dfs(int v) {
    vis[v] = true;
    for (auto u : adj[v]) if (!vis[u]) {
        dfs(u);
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
    // Verificar conectividade
    dfs(0);
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            ok = false;
            break;
        }
    }
    if (ok && n == m) {
        cout << "FHTAGN!" << endl;
    } else {
        cout << "NO" << endl;
    }
}

/*
O Cthulhu consiste em um Grafo CONEXO com APENAS UM CICLO.

Caso a gente remova uma aresta do ciclo temos uma árvore. 

Ou seja, precisamos verificar se o grafo é:
- Conexo. --> DFS
- n = m. (Pois, ao remover a aresta do ciclo temos n = m - 1 -> Definição de Árvore)
    -> Fazer essa verificação mostra se o Grafo tem APENAS UM CICLO
*/