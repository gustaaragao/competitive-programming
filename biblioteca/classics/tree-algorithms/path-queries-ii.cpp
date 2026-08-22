#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define f first
#define sec second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

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

const int N = 2e5 + 10;

struct SegTree {
    int n;
    int tree[2 * N];

    SegTree() {}

    void build(int n_nodes, const vector<int> &arr) {
        n = n_nodes;
        for (int i = 0; i < n; i++) tree[n + i] = arr[i + 1];
        for (int i = n - 1; i > 0; --i) tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
    }

    void update(int pos, int val) {
        pos--;
        for (tree[pos += n] = val; pos > 1; pos >>= 1)
            tree[pos >> 1] = max(tree[pos], tree[pos ^ 1]);
    }

    int query(int l, int r) {
        l--; r--;
        int ans = 0;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = max(ans, tree[l++]);
            if (r & 1) ans = max(ans, tree[--r]);
        }
        return ans;
    }
};



SegTree tree;
int par[N];
int sz[N];
int depth[N];
vi adj[N];

int head[N];
int in[N];
int val[N];
int timer_hld = 0;

void dfs(int u, int p) {
  par[u] = p;
  sz[u] = 1;
  int max_sz = 0;
  int heavy_node = -1;
  depth[u] = depth[p] + 1;
  for (int i = 0; i < (int)adj[u].size(); i++) {
    int v = adj[u][i];
    if (v != p) {
      dfs(v, u);
      sz[u] += sz[v];
      if (sz[v] > max_sz) {
        max_sz = sz[v];
        heavy_node = i;
      }
    }
  }
  if (heavy_node != -1) {
    swap(adj[u][0], adj[u][heavy_node]);
  }
}

void dfs_solve(int u, int p, int h) {
  head[u] = h;
  in[u] = ++timer_hld;

  for (auto v : adj[u]) {
    if (v != p) {
      dfs_solve(v, u, v == adj[u][0] ? h : v);
    }
  }
}

int query_path(int l, int r) {
  int ans = 0;

  while (head[l] != head[r]) {
    if (depth[head[l]] < depth[head[r]])
      swap(l, r);

    ans = max(ans, tree.query(in[head[l]], in[l]));
    l = par[head[l]];
  }

  if (depth[l] > depth[r])
    swap(l, r);

  ans = max(ans, tree.query(in[l], in[r]));
  return ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q;
  cin >> n >> q;

  for (int i = 1; i <= n; i++)
    cin >> val[i];

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  depth[0] = 0;
  dfs(1, 0);
  dfs_solve(1, 0, 1);

  vi vals2(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    vals2[in[i]] = val[i];
  }

  tree.build(n,vals2);

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int s, x;
      cin >> s >> x;
      val[s] = x;
      tree.update(in[s], x);
    } else {
      int l, r;
      cin >> l >> r;
      cout << query_path(l, r) << " ";
    }
  }
  cout << endl;

  return 0;
}
