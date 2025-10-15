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

const int MAXN = 193 + 10;

int n, m;
string fir, last, temp;
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
    unordered_map <string, int> mp;
    cin >> n >> m;
    int id = 0;
    for (int i = 0; i < n; i++) {
        cin >> fir;
        for (int j = 0; j < 3; j++) cin >> temp;
        cin >> last;
        if (!mp.contains(fir)) {
            mp[fir] = id;
            id++;
        }
        if (!mp.contains(last)) {
            mp[last] = id;
            id++;
        }
        adj[mp[fir]].pb(mp[last]);
    }
    for (int i = 0; i < m; i++) {
        cin >> fir;
        for (int j = 0; j < 3; j++) cin >> temp;
        cin >> last;
        if (!mp.contains(fir)) {
            mp[fir] = id;
            id++;
        }
        if (!mp.contains(last)) {
            mp[last] = id;
            id++;
        }
        int u = mp[fir], v = mp[last];
        fill(vis, vis+MAXN, false);
        // Há caminho de u para v?
        dfs(u);
        if (vis[v] == true) {
            cout << "Fact" << endl;
        } else {
            fill(vis, vis+MAXN, false);
            // Há caminho de v para u?
            dfs(v);
            if (vis[u] == true) {
                cout << "Alternative Fact" << endl;
            } else {
                cout << "Pants on Fire" << endl;
            }
        }
    }
}