#include <bits/stdc++.h>
using namespace std;
// Kahn Algorithm
// BFS + indegree: grau de incidência
const int MAXN = 1e5 + 10;
int n, m;
vector<int> adj[MAXN], indegree(MAXN, 0), order;
void topoSort() {
    queue<int> q;
    // priority_queue<int> pq; // Há uma preferência nos vértices
    for (int v = 0; v < n; v++) {
        if (indegree[v] == 0) q.push(v);
    }
    while (!q.empty()) {
        int v = q.front(); q.pop();
        // int v = pq.top(); pq.pop();
        order.push_back(v);
        for (auto u : adj[v]) {
            indegree[u]--;
            if (indegree[u] == 0) {
                q.push(u);
            }
        }
    }
}
signed main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        indegree[v]++;
    }
}