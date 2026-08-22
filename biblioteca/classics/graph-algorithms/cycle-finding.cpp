#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define f first
#define sec second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define int long long

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3fll;
const double EPS = 1e-9;
const ll MOD = 1e9 + 7;

struct Edge {
  int a, b, cost;
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector<Edge> edges;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.pb({u, v, w});
  }
  vi d(n + 1, 0);
  d[1] = 0;
  vi p(n + 1, -1);
  int x;
  for (int i = 0; i <= n; ++i) {
    x = -1;
    for (Edge e : edges)
      if (d[e.b] > d[e.a] + e.cost) {
        d[e.b] = max(LONG_LONG_MIN, d[e.a] + e.cost);
        p[e.b] = e.a;
        x = e.b;
      }
  }

  if (x == -1)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    int y = x;
    for (int i = 0; i < n; ++i)
      y = p[y];

    vi path;
    for (int cur = y;; cur = p[cur]) {
      path.pb(cur);
      if (cur == y && path.size() > 1)
        break;
    }
    reverse(all(path));

    for (int u : path)
      cout << u << ' ';
  }
  return 0;
}
