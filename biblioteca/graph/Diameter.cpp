#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int MAXN = 2e5+5;
int n, dist[MAXN];
vector<int> adj[MAXN];
void dfs(int v, int p) {
    for (auto u : adj[v]) if (u != p) {
        dist[u] = dist[v] + 1;
        dfs(u, v);
    }
}
void solve() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
       int u, v; cin >> u >> v; u--,v--;
       adj[u].pb(v);
       adj[v].pb(u);
    }
    dfs(0, -1);
    int d = 0, a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] > d) {
            d = dist[i];
            a = i;
        }
    }
    memset(dist, 0, sizeof(dist));
    dfs(a, -1);
    d = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] > d) {
            d = dist[i];
            b = i;
        }
    }
    cout << a << " " << b << endl;
    cout << d << endl;

