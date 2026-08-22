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
int sz[N], cnt[N]{1};
int tot = 0, ans = 0, mx_depth=-1;
bool done[N];
int k;

void calc_size(int u, int p) {
  sz[u] = 1;
  tot++;
  for (auto v : adj[u]) {
    if (v == p || done[v])
      continue;
    calc_size(v, u);
    sz[u] += sz[v];
  }
}

int find_cent(int u, int p) {
  for (auto v : adj[u]) {
    if (v == p || done[v])
      continue;
    if (sz[v] > tot / 2)
      return find_cent(v, u);
  }
  return u;
}

void add_cnt(int u, int p, bool filling, int depth=1) {
  if(depth >k) return;
  mx_depth = max(mx_depth, depth);
  if(filling) cnt[depth]++;
  else ans += cnt[k-depth];
  for(auto v : adj[u]){
    if(done[v] or v==p)continue;
    add_cnt(v,u,filling,depth+1);
  }

}

void centroid_tree(int u, int p) {
  tot = 0;
  calc_size(u, p);
  int cen = find_cent(u, p);
  done[cen]=1;
  mx_depth=0;
  for(auto v : adj[cen]){
    if(done[v]) continue;
    add_cnt(v,cen,false);
    add_cnt(v,cen,true);
  }
  fill(cnt+1, cnt+mx_depth+1,0);
  for(auto v : adj[cen]){
    if(!done[v]) centroid_tree(v,u);
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  centroid_tree(1, 0);

  cout << ans << endl;
  return 0;
}
