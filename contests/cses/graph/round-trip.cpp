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

const int MAX = 1e5 + 10;

int n, m;
vector<int> adj[MAX];
bool vis[MAX];
int parent[MAX], cycle_start, cycle_end;

bool dfs(int v) {
    vis[v] = true;
    for (auto u : adj[v]) {
        if (u==parent[v]) continue;
        if (vis[u]) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        parent[u] = v;
        if (dfs(u)) return true;
    }
    return false;
}

// Encontrar ciclos simples!
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(parent, -1, sizeof(parent));
    cycle_start = -1;

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int v = 0; v < n; v++) {
        if (!vis[v] and dfs(v)) {
            // Encontrou um ciclo
            break;
        }
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> cycle;
        cycle.pb(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.pb(v);
        cycle.pb(cycle_start);
        cout << sz(cycle) << endl;
        for (auto x : cycle) cout << x+1 << " ";
        cout << endl;
    }
}