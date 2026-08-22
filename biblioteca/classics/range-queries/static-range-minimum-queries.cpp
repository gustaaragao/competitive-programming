#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define f first
#define sec second
#define all(x) (x).begin(), (x).end()
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

int n;
vector<int> a;
vector<vector<int>> st;
vector<int> lg;

void build() {
  int K = __lg(n) + 1;
  st.assign(K, vector<int>(n));
  st[0] = a;

  for(int k = 1; k < K; k++) {
    for(int i = 0; i + (1 << k) <= n; i++) {
      st[k][i] = min(st[k-1][i], st[k-1][i + (1 << (k-1))]);
    }
  }

  lg.assign(n+1, 0);
  for(int i = 2; i <= n; i++)
    lg[i] = lg[i/2] + 1;
}

int query(int l, int r) {
  int k = lg[r - l + 1];
  return min(st[k][l], st[k][r - (1 << k) + 1]);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int q;
  cin >> n >> q;

  a.resize(n);
  for(auto &x : a) cin >> x;

  build();

  while(q--){
    int x, b;
    cin >> x >> b;
    x--; b--;
    cout << query(x, b) << '\n';
  }
}
