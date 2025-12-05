#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define sz(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << x << endl

const int MAXN = 1e5 + 10;

int n, m; bool vis[MAXN];
vector<int> adj[MAXN], indegree(MAXN, 0);

void dfs(int v) {
    vis[v] = true;
    for (auto u : adj[v]) if (!vis[u]) {
        dfs(u);
    }
}

deque<int> topoSort() {
    deque<int> order;
    queue<int> q;
    for (int v = 0; v < n; v++) {
        if (indegree[v] == 0) 
        q.push(v);
    }
    while(!q.empty()) {
        int v = q.front(); q.pop();
        order.push_back(v);
        for (auto u : adj[v]) {
            indegree[u]--;
            if (indegree[u] == 0) 
                q.push(u);
        }
    }
    return order;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        adj[a].pb(b);
        indegree[b]++;
    }
    // Existe caminho entre 1 e N?
    dfs(0);
    if (!vis[n-1]) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    deque<int> order = topoSort();
    while (order.front() != 0) order.pop_front();
    vector<int> dist(MAXN, -1), parent(MAXN, -1);
    // dist[u] = max(dist[u], dist[v] + 1), sendo v -> u.
    // Se fizermos a dp na ordem do toposort, garantimos que processamos apenas o u, quando o v já estiver
    // completamente processado.
    dist[0] = 1;
    for (auto v : order) {
        for (auto u : adj[v]) {
            if (dist[v] + 1 > dist[u]) {
                dist[u] = dist[v] + 1;
                parent[u] = v;
            }
        }
    }
    cout << dist[n-1] << endl;
    int v = n-1;
    vector<int> path;
    while (v != -1) {
        path.pb(v);
        v = parent[v];
    }
    reverse(all(path));
    for (auto x : path) {
        cout << x+1 << " ";
    }
    cout << endl;
}

/*
1 --> 2 ---> 5
|            ^
|     -------|
v     |
3 --> 4

1 2 3 4 5
*/