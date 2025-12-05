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
 
int n, m;
vector<int> adj[MAXN], indegree(MAXN, 0), order;
 
void topoSort() {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int v = 0; v < n; v++) {
        if (indegree[v] == 0) {
            pq.push(v);
        }
    }
 
    while (!pq.empty()) {
        int v = pq.top(); pq.pop();
        order.push_back(v);
        for (auto u : adj[v]) {
            indegree[u]--;
            if (indegree[u] == 0) {
                pq.push(u);
            }
        }
    }
}
 
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v);
        indegree[v]++;
    }
    topoSort();
    for (auto x : order) cout << x + 1 << " ";
    cout << endl;
}