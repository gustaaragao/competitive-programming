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

template<typename T>
struct LazySegTree {
    int n;
    vector<T> tree, lazy;
    T neutro = 0;

    LazySegTree(int n) : n(n) {
        tree.assign(4 * n, neutro);
        lazy.assign(4 * n, 0);
    }

    T combina(T a, T b) {
        return a + b;
    }

    void push(int node, int l, int r) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node] * (r - l + 1);

            if (l != r) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }

            lazy[node] = 0;
        }
    }

    void build(int node, int l, int r, const vector<T>& arr) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * node, l, mid, arr);
        build(2 * node + 1, mid + 1, r, arr);
        tree[node] = combina(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int ql, int qr, T val) {
        push(node, l, r);

        if (ql > r || qr < l) return;

        if (ql <= l && r <= qr) {
            lazy[node] += val;
            push(node, l, r);
            return;
        }

        int mid = l + (r - l) / 2;
        update(2 * node, l, mid, ql, qr, val);
        update(2 * node + 1, mid + 1, r, ql, qr, val);

        tree[node] = combina(tree[2 * node], tree[2 * node + 1]);
    }

    T query(int node, int l, int r, int ql, int qr) {
        push(node, l, r);

        if (ql > r || qr < l) return neutro;
        if (ql <= l && r <= qr) return tree[node];

        int mid = l + (r - l) / 2;
        return combina(query(2 * node, l, mid, ql, qr),
                       query(2 * node + 1, mid + 1, r, ql, qr));
    }

};

const int N = 2e5+10;

LazySegTree<int> tree(N);
int par[N];
int sz[N];
vi adj[N];

int head[N];
int in[N];
int val[N];
int timer_hld=0;

void dfs(int u, int p){
  par[u]=p;
  sz[u]=1;
  int max_sz=0;
  int heavy_node=-1;
  for(int i=0;i<(int)adj[u].size();i++){
    int v = adj[u][i];
    if(v!=p){
      dfs(v,u);
      sz[u]+=sz[v];
      if(sz[v] > max_sz){
        max_sz=sz[v];
        heavy_node=i;
      }
    }
  }
  if(heavy_node != -1){
    swap(adj[u][0], adj[u][heavy_node]);
  }
}

void dfs_solve(int u, int p, int h){
  head[u] = h;
  in[u] = ++timer_hld;

  for(auto v : adj[u]){
    if(v!=p){
      dfs_solve(v,u,v==adj[u][0]?h:v);
    }
  }
}

int query_path(int u, int n_nodes){
  int ans=0;

  while(head[u] != head[1]){
    ans += tree.query(1,1,n_nodes, in[head[u]],in[u]);
    u=par[head[u]];
  }

  ans += tree.query(1,1,n_nodes, in[1], in[u]);
  return ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n,q; cin >> n >> q;

  for(int i=1;i<=n;i++) cin >> val[i];

  for(int i=0;i<n-1;i++){
    int u,v; cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  dfs(1,0);
  dfs_solve(1,0,1);

  vi vals2(n+1,0);
  for(int i=1;i<=n;i++){
    vals2[in[i]]=val[i];
  }

  tree.build(1,1,n,vals2);

  while(q--){
    int t; cin >> t;
    if(t==1){
      int s,x; cin >> s >> x;
      int dif = x-val[s];
      val[s]=x;
      tree.update(1,1,n,in[s],in[s],dif);
    }else{
      int s; cin >> s;
      cout << query_path(s,n) << endl;
    }
  }

  return 0;
}
