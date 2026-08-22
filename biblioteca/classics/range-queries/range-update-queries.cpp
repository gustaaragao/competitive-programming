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

template <class T> struct BIT {
  int n;
  vector<T> bit;

  BIT(int n) : n(n), bit(n + 1, 0) {}

  void add(int i, T val) {
    for (++i; i <= n; i += i & -i)
      bit[i] += val;
  }

  void range_add(int l, int r, T val) {
    add(l, val);
    if (r + 1 <= n) add(r + 1, -val);
  }

  T point_query(int idx) {
    T resp = 0;
    for (++idx; idx > 0; idx -= idx & -idx)
      resp += bit[idx];
    return resp;
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q;
  cin >> n >> q;

  BIT<int> bt(n + 1);
  vi a(n+1,0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for(int i=1;i<=n;i++){
    bt.add(i,a[i]-a[i-1]);
  }

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r, val;
      cin >> l >> r >> val;
      bt.range_add(l, r, val);
    } else {
      int i;
      cin >> i;
      cout << bt.point_query(i) << endl;
    }
  }

  return 0;
}
