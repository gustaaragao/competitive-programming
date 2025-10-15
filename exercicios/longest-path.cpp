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

const int MAXN = 1e4 + 10;

vector<int> adj[MAXN];
int n, dist[MAXN];

void dfs(int v) {
    for (auto u : adj[v]) if(dist[u] == -1) {
        dist[u] = dist[v] + 1;
        dfs(u);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    fill(dist, dist+MAXN, -1);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dist[0] = 0;
    dfs(0);
    // Passo 1: Encontrar o vértice mais distante de 0
    int maxdist = -1, pos = -1;
    for (int v = 0; v < n; v++) {
        if (dist[v] > maxdist) {
            maxdist = dist[v];
            pos = v;
        }
    }
    // Passo 2: Encontrar o vértice mais distante de "pos"
    fill(dist, dist+MAXN, -1);
    dist[pos] = 0;
    dfs(pos);
    int ans = -1;
    for (int v = 0; v < n; v++) ans = max(ans, dist[v]);
    cout << ans << endl;
}