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

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n,q; cin >> n >> q;
  vvi pref(n+1, vi(n+1,0));
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      char c; cin >> c;
      int val = (c=='*'?1:0);
      pref[i][j] = val + pref[i-1][j] + pref[i][j-1] -pref[i-1][j-1];
    }
  }

  while(q--){
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << pref[x2][y2] - pref[x1-1][y2] - pref[x2][y1-1] + pref[x1-1][y1-1] << endl;
  }

  return 0;
}
