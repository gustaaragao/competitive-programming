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

const int N = 2e5 + 10;
vi adj[N];
int ans[N], sz[N], cnt[N], cor[N];
bool big[N];
int resp=0;

void dfs_size(int u, int p) {
  sz[u] = 1;
  for (auto v : adj[u])
    if (v != p) {
      dfs_size(v, u);
      sz[u] += sz[v];
    }
}

void add(int u, int p, int val) {
  if(cnt[cor[u]]==0) resp+=val;
  cnt[cor[u]] += val;
  if(cnt[cor[u]]==0) resp+=val;
  for (auto v : adj[u]) {
    if (v != p and !big[v]) {
      add(v,u,val);
    }
  }
}

void dfs_dsu(int u, int p, bool keep) {
  int bigchild = -1, mx = -1;
  for (auto v : adj[u]) {
    if (v == p)
      continue;
    if (sz[v] > mx)
      mx = sz[v], bigchild = v;
  }
  for (auto v : adj[u]) {
    if (v != p and v!=bigchild) {
      dfs_dsu(v, u, false);
    }
  }

  if (bigchild != -1) {
    dfs_dsu(bigchild, u, true);
    big[bigchild]=1;
  }

  add(u, p, 1);
  ans[u]=resp;
  if (bigchild!=-1) {
    big[bigchild] = 0;
  }
  if (!keep) {
    add(u, p, -1);
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vi vals;
  for (int i = 1; i <= n; i++){
    cin >> cor[i];
    vals.pb(cor[i]);
  }

  sort(all(vals));
  vals.erase(unique(all(vals)),vals.end());

  for(int i=1;i<=n;i++){
    cor[i] = lower_bound(all(vals), cor[i])-vals.begin();
  }

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  dfs_size(1, 0);
  dfs_dsu(1, 0, false);

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}
