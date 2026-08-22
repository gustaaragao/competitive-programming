#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
// #define int long long
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define nl '\n'

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<ll> vl;

const int MAXN = 1e3 + 5;
const ll INF = 2e9;

ll n, m, k, q;

vector<int> g[501];
vector<int> mt;
vector<bool> used;

bool try_kuhn(int v) {
    if (used[v])
        return false;
    used[v] = true;
    for (int to : g[v]) {
        if (mt[to] == -1 || try_kuhn(mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> n >> m >> k;

    for (ll i = 0; i < k; i++) {
        ll a, b; cin >> a >> b;
        a--, b--;
        g[a].pb(b);
    }

    mt.assign(m, -1);
    for (int v = 0; v < n; ++v) {
        used.assign(n, false);
        try_kuhn(v);
    }

    ll cnt = 0;
    vector<pair<ll, ll>> ans;
    for (int i = 0; i < m; ++i) {
        if (mt[i] != -1) {
            cnt++;
            ans.eb(mt[i] + 1, i + 1);
        }
    }

    cout << cnt << nl;
    for (auto [a, b] : ans) cout << a << " " << b << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}
