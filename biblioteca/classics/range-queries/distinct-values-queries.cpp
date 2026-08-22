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

template<class T> struct SegmentTree {
  const T ID{};
  T cmb(T a, T b) { return a + b; }
  int N = 1; vector<T> seg;
  SegmentTree(int _N) {
    while (N < _N) N *= 2;
    seg.assign(2*N, ID);
  }
  void update(int p, T val) { // set val at position p
    seg[p += N] = val;
    for (p /= 2; p > 0; p /= 2) {
      seg[p] = cmb(seg[2*p], seg[2*p+1]);
    }
  }
  T query(int l, int r) { // zero-indexed, inclusive
    T lf = ID, rf = ID;
    for (l += N, r += N + 1; l < r; l /= 2, r /= 2) {
      if (l & 1) lf = cmb(lf, seg[l++]);
      if (r & 1) rf = cmb(seg[--r], rf);
    }
    return cmb(lf, rf);
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q;
  cin >> n >> q;
  vi a(n),ans(q);
  for(auto &x:a)cin >>x;

  map<int, vpii> Queries;
  for(int i=0;i<q;i++){
    int l,r; cin >> l >> r;
    Queries[r-1].pb({l-1,i});
  }

  map<int,int> lstOc;
  SegmentTree<int> st(n);
  for(int i=0;i<n;i++){
    if(lstOc.count(a[i])){
      st.update(lstOc[a[i]],0);
    }
    st.update(i,1);
    lstOc[a[i]]=i;
    for(auto [l,ind]:Queries[i]){
      ans[ind]=st.query(l,i);
    }
  }

  for(auto i : ans) cout << i << endl;

  return 0;
}
