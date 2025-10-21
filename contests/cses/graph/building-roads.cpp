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

int dfs(int v) {
    vis[v] = true;
    int last_vertex = v;
    for (auto u : adj[v]) if (!vis[u]) {
        last_vertex = dfs(u);
    }
    return last_vertex;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<int> last_vertices;
    for (int v = 0; v < n; v++) if (!vis[v]) {
        last_vertices.pb(dfs(v));
    }
    if (sz(last_vertices) == 1) {
        cout << 0 << endl;
    } else {
        int len = sz(last_vertices) - 1;
        cout << len << endl;
        for (int i = 0; i < len; i++) {
            cout << last_vertices[i]+1 << " " << last_vertices[i+1]+1 << endl;
        }
    }
}