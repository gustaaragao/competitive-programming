#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define int long long
#define endl '\n' //<< flush
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cerr << #x << " = " << x << endl
#define uniq(v) sort(all(v)); v.erase(unique(all(v)), v.end())
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef pair<int, int> pi;
// const int MOD = 1e9 + 7; // 998244353;
// const int INF = 0x3f3f3f3f;
// const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 2e5+5;

struct Edge {
    int to, id;
};

vector<int> ans;
bool is_bridge[MAXN];
vector<Edge> adj[MAXN];
int n, m, s, t, best, removed, cost[MAXN],
    dp[MAXN], lvl[MAXN], parent[MAXN], parent_edge[MAXN];

void dfs(int v) {
    dp[v] = 0;

    for (auto [u, id] : adj[v]) {
        if (id == parent_edge[v]) continue;
        if (id == removed) continue;

        if (lvl[u] == 0) {
            parent[u] = v;
            parent_edge[u] = id;
            lvl[u] = lvl[v] + 1;
            dfs(u);
            dp[v] += dp[u];
        } else if (lvl[u] < lvl[v]) {
            dp[v]++;
        } else if (lvl[u] > lvl[v]) {
            dp[v]--;
        }
    }

    if (parent[v] != -1 && dp[v] == 0) {
        is_bridge[parent_edge[v]] = true;
    }
}

void get_bridges() {
    memset(dp, 0, sizeof(dp));
    memset(lvl, 0, sizeof(lvl));
    memset(parent, -1, sizeof(parent));
    memset(parent_edge, -1, sizeof(parent_edge));
    memset(is_bridge, 0, sizeof(is_bridge));

    lvl[s] = 1;
    dfs(s);
}

vector<int> get_path() {
    vector<int> path;
    if (lvl[t] == 0) return path;

    int cur = t;
    while (cur != s) {
        path.pb(parent_edge[cur]);
        cur = parent[cur];
    }

    reverse(all(path));
    return path;
}

void solve() {
    removed = -1;
    best = LLONG_MAX;
    ans.clear();

    cin >> n >> m >> s >> t;
    s--, t--;

    for (int i = 0; i < n; i++) adj[i].clear();

    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--, y--;
        adj[x].pb({y, i});
        adj[y].pb({x, i});
        cost[i] = w;
    }

    get_bridges();

    // Caso 1: s e t já estão desconectados
    if (lvl[t] == 0) {
        cout << 0 << endl;
        cout << 0 << endl;
        return;
    }

    // Caso 2: uma aresta só
    vector<int> path = get_path();
    for (auto id : path) {
        if (is_bridge[id] && cost[id] < best) {
            ans = {id};
            best = cost[id];
        }
    }

    // Caso 3: duas arestas
    for (auto e1 : path) {
        removed = e1;
        get_bridges();

        // e1 sozinho já desconecta
        if (lvl[t] == 0) {
            if (cost[e1] < best) {
                best = cost[e1];
                ans = {e1};
            }
            continue;
        }

        vector<int> new_path = get_path();
        for (auto e2 : new_path) {
            if (is_bridge[e2] && cost[e1] + cost[e2] < best) {
                ans = {e1, e2};
                best = cost[e1] + cost[e2];
            }
        }
    }

    if (best == LLONG_MAX) {
        cout << -1 << endl;
        return;
    }

    cout << best << endl;
    cout << ans.size() << endl;
    for (auto id : ans) cout << id + 1 << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}
