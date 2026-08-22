#include <bits/stdc++.h>

#define nl '\n'
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<long long, long long>
#define pb push_back

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

const ll INF = 1e14 + 5;
const ll P = 13;
const ll M = 1e8;
const ll LG = 32;
const ll MAX = 1e2 + 5;

int n, m, k, h, w, q;

vector<vector<ll>> g;
vector<bool> vis;

struct Edge {
    ll a, b, cost;
};

void dfs(ll u) {
    vis[u] = true;
    for (ll v : g[u]) {
        if (!vis[v]) dfs(v);
    }
}

void solve() {
    cin >> n >> m;

    vis.assign(n, false);
    g.assign(n, vector<ll>());
    vector<Edge> edges(m);

    for (ll i = 0; i < m; i++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].cost;
        edges[i].a--, edges[i].b--;
        g[edges[i].a].pb(edges[i].b);
    }

    vector<ll> d(n, -INF);
    d[0] = 0;

    vector<bool> bad(n, false);
    for (int i = 0; i < n; ++i) {
        for (Edge e : edges)
            if (d[e.a] > -INF)
                if (d[e.b] < d[e.a] + e.cost) {
                    d[e.b] = min(INF, d[e.a] + e.cost);
                    if (i == n-1) bad[e.b] = true;
                }
    }

    for (ll i = 0; i < n; i++) {
        if (!vis[i] && bad[i]) {
            dfs(i);
        }
    }

    if (vis[n-1]) {
        cout << -1 << nl;
    } else {
        cout << d[n-1] << nl;
    }
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
    //cin >> t;
	for (int i = 1; i <= t; i++) {
	    solve();
	}
	return 0;
}
