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

template <typename T> struct PersistentSegTree {
  struct Node {
    T sum;
    int l, r; // Índices para o filho esquerdo e direito no vector 'tree'
    Node(T sum = 0, int l = 0, int r = 0) : sum(sum), l(l), r(r) {}
  };

  int n;
  vector<Node> tree;
  vector<int> roots; // Armazena o índice da raiz de cada versão
  T neutro = 0;      // Elemento neutro para a soma

  // Construtor
  PersistentSegTree(int n) : n(n) {
    // O índice 0 será o nosso nó "nulo" ou vazio
    tree.push_back(Node(neutro, 0, 0));
    roots.push_back(0); // A versão 0 aponta para o nó nulo inicialmente
  }

  T combina(T a, T b) { return a + b; }

  int clone(int node_idx) {
    tree.push_back(tree[node_idx]);
    return tree.size() - 1;
  }

  int copy_version(int version_id) {
    roots.push_back(roots[version_id]);
    return roots.size() - 1;
  }

  // Build interno (Constrói a versão inicial baseada em um array)
  int build(int l, int r, const vector<T> &arr) {
    int node = tree.size();
    tree.push_back(Node()); // Cria um novo nó

    if (l == r) {
      tree[node].sum = arr[l];
      return node;
    }

    int mid = l + (r - l) / 2;
    tree[node].l = build(l, mid, arr);
    tree[node].r = build(mid + 1, r, arr);
    tree[node].sum = combina(tree[tree[node].l].sum, tree[tree[node].r].sum);

    return node;
  }

  // Update interno (Retorna o índice da nova raiz)
  int update(int curr_root, int l, int r, int pos,
             T val) {
    int node = clone(curr_root);
    // 3. Chegamos na folha: modifica in-place e RETORNA O ÍNDICE
    if (l == r) {
      tree[node].sum = val; // Altere para '=' se for substituição
      return node;
    }

    int mid = l + (r - l) / 2;

    if (pos <= mid) {
      // O filho esquerdo do clone recebe o novo caminho atualizado
      tree[node].l = update(tree[node].l, l, mid, pos, val);
    } else {
      // O filho direito do clone recebe o novo caminho atualizado
      tree[node].r = update(tree[node].r, mid + 1, r, pos, val);
    }

    // Recalcula a soma usando os filhos
    tree[node].sum =
        combina(tree[tree[node].l].sum, tree[tree[node].r].sum);

    // Retorna o índice do nó que acabamos de modificar
    return node;
  }

  // Query interna no intervalo [ql, qr] em uma raiz específica
  T query(int node, int l, int r, int ql, int qr) {
    if (node == 0 || ql > r || qr < l)
      return neutro;
    if (ql <= l && r <= qr)
      return tree[node].sum;

    int mid = l + (r - l) / 2;
    return combina(query(tree[node].l, l, mid, ql, qr),
                   query(tree[node].r, mid + 1, r, ql, qr));
  }

  // --- FUNÇÕES PARA USAR NA MAIN ---

  // Constrói a versão 0 a partir de um array.
  // Retorna o índice da versão criada (sempre será 1 se chamado logo após
  // instanciar)
  int build(const vector<T> &arr) {
    int root_idx = build(0, n - 1, arr);
    roots.push_back(root_idx);
    return roots.size() - 1; // Retorna o ID da versão recém-criada
  }

  // Atualiza um elemento partindo de uma versão base.
  // Retorna o ID da nova versão criada.
  void update(int base_version, int pos, T val) {
    roots[base_version] = update(roots[base_version], 0, n - 1, pos, val);
  }

  // Consulta no intervalo [l, r] de uma versão específica
  T query(int version, int l, int r) {
    return query(roots[version], 0, n - 1, l, r);
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q;
  cin >> n >> q;
  vi a(n);
  for (auto &x : a)
    cin >> x;
  PersistentSegTree<int> st(n);
  st.build(a);
  while (q--) {
    int t;
    cin >> t;
    int k;
    cin >> k;
    if (t == 1) {
      int i, x;
      cin >> i >> x;
      i--;
      st.update(k, i, x);
    } else if (t == 2) {
      int l, r;
      cin >> l >> r;
      l--, r--;
      cout << st.query(k, l, r) << endl;
    } else {
      st.copy_version(k);
    }
  }

  return 0;
}
