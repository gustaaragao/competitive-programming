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
int n, m, ans;
vector<int> adj[MAXN];
bool cats[MAXN], vis[MAXN];

void dfs(int v, int cnt) { // cnt -> armazena o contador de gatos consecutivos
    vis[v] = true;
    // Verificar a presença de gato
    if (cats[v]) cnt++;
    else cnt = 0;

    // Finaliza a busca para cnt > m
    if (cnt > m) return;

    bool is_leaf = true;
    for (auto u : adj[v]) if (!vis[u]) {
        is_leaf = false;
        dfs(u, cnt);
    }

    // Chegou em uma folha?
    if (is_leaf) ans++;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> cats[i];
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0, 0);
    cout << ans << endl;
}