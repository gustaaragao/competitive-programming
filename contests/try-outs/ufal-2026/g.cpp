#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
typedef long long ll;
typedef pair<int, int> pi;
const int MAXN = 3e5 + 10;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<pair<ll, ll>> adj[MAXN];
ll n, m, k, dist[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        ll u, v, w; cin >> u >> v >> w; u--, v--;
        adj[v].pb({u, w});
        adj[u].pb({v, w});
    }

    auto possible = [&](int x) {
        memset(dist, LINF, sizeof(dist));

        deque<int> q; q.push_front(0); dist[0] = 0;
        while (!q.empty()) {
            int v = q.front(); q.pop_front();
            // cout << "v: " << v << endl;
            for (auto [u, w] : adj[v]) if (dist[v] + (w > x ? 1 : 0) < dist[u]) {
                dist[u] = dist[v] + (w > x ? 1 : 0);
                if ((w > x ? 1 : 0)) {
                    q.push_back(u);
                } else {
                    q.push_front(u);
                }
            }
        }
        if (dist[n-1] <= k) return true;
        else return false;
    };

    ll ans = -1, l = 0, r = 1e9;
    while (l <= r) {
        ll m = l + (r - l) / 2;
        if (possible(m)) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << ans << endl;
}