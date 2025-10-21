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

int n, m, c;
vector<int> adj[MAX];
int color[MAX];

// Checar se um grafo é bipartido
bool bfs(int s) {
    queue<int> q; q.push(s); color[s] = 0;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (auto u : adj[v]) {
            if (color[u] == -1) { // não visitado
                color[u] = !color[v];
                q.push(u);
            } else if (color[u] == color[v]) {
                return false;
            }
        }
    }
    return true;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(color, -1, sizeof(color));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    // Definindo as cores
    bool ok = true;
    for (int i = 0; i < n; i++) if(color[i] == -1) {
        ok = bfs(i);
        if (!ok) break;
    }
    if (!ok) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << color[i]+1 << " ";
        }
        cout << endl;
    }
}