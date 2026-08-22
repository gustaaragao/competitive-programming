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
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5+10;

struct treap {
  //This is an implicit treap which investigates here on an array
  struct node {
    int val, sz, prior, lazy, sum, mx, mn, repl;
    bool repl_flag, rev;
    node *l, *r, *par;
    node() {
      lazy = 0;
      rev = 0;
      sum = 0;
      val = 0;
      sz = 0;
      mx = 0;
      mn = 0;
      repl = 0;
      repl_flag = 0;
      prior = 0;
      l = NULL;
      r = NULL;
      par = NULL;
    }
    node(int _val) {
      val = _val;
      sum = _val;
      mx = _val;
      mn = _val;
      repl = 0;
      repl_flag = 0;
      rev = 0;
      lazy = 0;
      sz = 1;
      prior = rnd();
      l = NULL;
      r = NULL;
      par = NULL;
    }
  };
  typedef node* pnode;
  pnode root;
  map<int, pnode> position;//positions of all the values
  //clearing the treap
  void clear() {
    root = NULL;
    position.clear();
  }

  treap() {
    clear();
  }

  int size(pnode t) {
    return t ? t->sz : 0;
  }
  void update_size(pnode &t) {
    if(t) t->sz = size(t->l) + size(t->r) + 1;
  }

void lazy_rev_upd(pnode &t) {
    if( !t or !t->rev ) return;
    t->rev = false;
    swap(t->l, t->r);
    if( t->l )  t->l->rev ^= true;
    if( t->r )  t->r->rev ^= true;
  }

  //split node t in l and r by key k
  //so first k+1 elements(0,1,2,...k) of the array from node t
  //will be split in left node and rest will be in right node
  void split(pnode t, pnode &l, pnode &r, int k, int add = 0) {
    if(t == NULL) {
      l = NULL;
      r = NULL;
      return;
    }
    lazy_rev_upd(t);
    int idx = add + size(t->l);
    if(t->l) t->l->par = NULL;
    if(t->r) t->r->par = NULL;
    if(idx <= k)
      split(t->r, t->r, r, k, idx + 1), l = t;
    else
      split(t->l, l, t->l, k, add), r = t;

    update_size(t);
  }
  //merge node l with r in t
  void merge(pnode &t, pnode l, pnode r) {
    lazy_rev_upd(l);
    lazy_rev_upd(r);
    if(!l) {
      t = r;
      return;
    }
    if(!r) {
      t = l;
      return;
    }
    if(l->prior > r->prior)
      merge(l->r, l->r, r), t = l;
    else
      merge(r->l, l, r->l), t = r;
    update_size(t);
  }
  //insert val in position a[pos]
  //so all previous values from pos to last will be right shifted
  void insert(int pos, int val) {
    if(root == NULL) {
      pnode to_add = new node(val);
      root = to_add;
      position[val] = root;
      return;
    }

    pnode l, r, mid;
    mid = new node(val);
    position[val] = mid;

    split(root, l, r, pos - 1);
    merge(l, l, mid);
    merge(root, l, r);
  }
  //reverse all the values from qL to qR
  void reverse(int qL, int qR) {
    pnode l, r, mid;

    split(root, l, r, qL - 1);
    split(r, mid, r, qR - qL);

    mid->rev ^= 1;
    merge(r, mid, r);
    merge(root, l, r);
  }

  //inorder traversal to get indexes chronologically
  void inorder(pnode cur) {
    if(cur == NULL) return;
    lazy_rev_upd(cur);
    inorder(cur->l);
    char res = cur->val+'a';
    cout << res;
    inorder(cur->r);
  }
  //print current array values serially
  void print_array() {
    inorder(root);
    cout << endl;
  }
};

treap t;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n,q; cin >> n >> q;
  string s; cin >> s;
  for(int i=0;i<n;i++){
    char c = s[i];
    int x = c-'a';
    t.insert(i,x);
  }

  while(q--){
    int l,r; cin  >> l >> r;
    l--,r--;
    t.reverse(l,r);
  }

  t.print_array();

  return 0;
}
