#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6;
int n, m, dist[MAXN];
vector<int> g[MAXN];
int par[MAXN];
void bfs(int s) {
    queue<int> q; q.push(s); dist[s] = 0;
    while (!q.empty() ){
        int v=q.front(); q.pop();
        for (auto u : g[v]) if (dist[u] == -1) {
            q.push(u);
            dist[u] = dist[v] + 1;
            par[u] = v;
        }
    }
}

int main() {
    cin >> n >> m;
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bfs(0);
    if (dist[n-1] == -1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    int cur = n-1;
    par[0] = -1;
    vector<int> path;
    cout << dist[n-1] +1<< endl;
    while(cur != -1  ) {
        path.push_back(cur+1);
        cur = par[cur];
    }
    reverse(path.begin(), path.end());
    for (auto x : path) cout << x << " ";
    cout << endl;
}
