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

int n, q;
vector<int> adj[MAXN], path;
bool vis[MAXN];
int subtree_size[MAXN];

void dfs(int v) {
    vis[v] = true;
    subtree_size[v] = 1;
    path.pb(v);
    for (auto u : adj[v]) if(!vis[u]) {
        dfs(u);
        subtree_size[v] += subtree_size[u];
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> q;
    for (int v = 2; v <= n; v++) {
        int u; cin >> u;
        adj[u-1].pb(v-1);
    }

    for (int v = 0; v < n; v++)
        sort(all(adj[v]));
    
    dfs(0);

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[path[i]] = i;
    }

    while (q--) {
        int u, k; cin >> u >> k;
        u--; k--;
        // Passo 1: Encontrar u em path
        int pos = mp[u];
        
        // o Kth elemento na subtree enraizada em u está na posição path[pos + k]
        if (k < subtree_size[u]) {
            cout << (path[pos + k] + 1) << endl;
        } else {
            cout << -1 << endl;
        }
    }
}