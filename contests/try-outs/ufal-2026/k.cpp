#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back

typedef long long ll;
typedef pair<int, int> pi;

const int MAXN = 1e5 + 10;

bool vis[MAXN];
int n, m, color[MAXN];
vector<int> adj[MAXN];

bool dfs(int v) {
    for (auto u : adj[v]) {
        if (color[u] == -1) {
            color[u] = (color[v] == 1) ? 2 : 1;
            if (!dfs(u)) return false;
        } else if (color[u] == color[v]) {
            return false;
        }
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) color[i] = -1;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bool valid = true;
    for (int v = 0; v < n; v++) {
        if (color[v] == -1) {
            color[v] = 1;
            if (!dfs(v)) {
                valid = false;
                break;
            }
        }
    }

    if (!valid) {
        cout << "IMPOSSIVEL" << endl;
    } else {
        cout << "POSSIVEL" << endl;
        vector<int> a, b;
        for (int v = 0; v < n; v++) {
            // cout << color[v] << " ";
            if (color[v] == 1) a.pb(v+1);
            else b.pb(v+1);
        }
        // cout << endl;
        cout << (int) a.size() << " " << (int) b.size() << endl;
        for (auto x : a) cout << x << " ";
        cout << endl;
        for (auto x : b) cout << x << " ";
        cout << endl;
    }
}