#include <bits/stdc++.h>
using namespace std;

// Problema dynamic connectivity

#define endl '\n'
#define f first
#define sec second
#define pb push_back

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 3e5 + 10;

vector<pii> seg[4 * N];
map<pii, int> entradas; // entradas das arestas na query
int ans[N];

// DSU com rollback
struct persistent_dsu {
  struct state {
    int u, v, rnku, rnkv;
    state() {
      u = -1;
      v = -1;
      rnkv = -1;
      rnku = -1;
    }
    state(int _u, int _rnku, int _v, int _rnkv) {
      u = _u;
      rnku = _rnku;
      v = _v;
      rnkv = _rnkv;
    }
  };

  stack<state> st;
  int par[N], depth[N];
  int comp;
  
  persistent_dsu() {
    comp = 0;
    memset(par, -1, sizeof(par));
    memset(depth, 0, sizeof(depth));
  }

  int root(int x) {
    if (x == par[x])
      return x;
    return root(par[x]);
  }

  void init(int n) {
    comp = n;
    for (int i = 0; i <= n; i++) {
      par[i] = i;
      depth[i] = 1;
    }
  }

  bool connected(int x, int y) { return root(x) == root(y); }

  void unite(int x, int y) {
    int rx = root(x), ry = root(y);
    if (rx == ry) {
      st.push(state());
      return;
    }
    
    st.push(state(rx, depth[rx], ry, depth[ry]));

    if (depth[rx] < depth[ry]) {
      par[rx] = ry;
    } else if (depth[ry] < depth[rx]) {
      par[ry] = rx;
    } else {
      par[rx] = ry;
      depth[ry]++; 
    }
    comp--;
  }

  void backtrack(int c) {
    while (!st.empty() && c) {
      if (st.top().u == -1) {
        st.pop();
        c--;
        continue;
      }
      par[st.top().u] = st.top().u;
      par[st.top().v] = st.top().v;
      depth[st.top().u] = st.top().rnku;
      depth[st.top().v] = st.top().rnkv;
      st.pop();
      c--;
      comp++;
    }
  }
};

persistent_dsu d;

void upd(int p, int l, int r, int ql, int qr, pii val) {
  if (l > qr or r < ql)
    return;
  // Seg[p] guarda as arestas contidas em [L,R]
  if (ql <= l and r <= qr) {
    seg[p].pb(val);
    return;
  }
  int m = (l + r) / 2;
  upd(2 * p, l, m, ql, qr, val);
  upd(2 * p + 1, m + 1, r, ql, qr, val);
}

void query(int p, int l, int r) {
  if (l > r)
    return;
  int prev = d.st.size();

  // Uniao de todas arestas pertencentes a seg[p]
  for (auto &edge : seg[p])
    d.unite(edge.f, edge.sec);

  if (l == r) {
    ans[l] = d.comp;
    // Damos rollback no DSU para o DSU sem as arestas de sep[p]
    d.backtrack(d.st.size() - prev);
    return;
  }

  int m = (l + r) / 2;
  query(2 * p, l, m);
  query(2 * p + 1, m + 1, r);
  
  // Rollback novamente, ja lemos esse node e estamos subindo na seg tree
  d.backtrack(d.st.size() - prev);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  freopen("connect.in", "r", stdin);
  freopen("connect.out", "w", stdout);
  
  int n, k; 
  cin >> n >> k;

  vi queries;
  d.init(n);
  for (int i = 1; i <= k; i++) {
    char t;
    cin >> t;
    if (t == '?') {
      queries.pb(i);
    } else if (t == '+') {
      int u, v;
      cin >> u >> v;
      if (u > v)
        swap(u, v);
      entradas[{u, v}] = i;
    } else if (t == '-') {
      int u, v;
      cin >> u >> v;
      if (u > v)
        swap(u, v);
      pii p = {u, v};
      // aresta (u,v) entra em entradas[(u,v)] e sai em i-1
      upd(1, 1, k, entradas[p], i - 1, p);
      // apagamos a aresta
      entradas.erase(p);
    }
  }
  
  // Adicionamos as arestas que nao sao removidas
  for (auto& p : entradas) {
    // p.second = tempo de entrada, p.first = aresta
    upd(1, 1, k, p.second, k, p.first);
  }
  query(1, 1, k);
  for (auto i : queries) {
    cout << ans[i] << endl;
  }

  return 0;
}
