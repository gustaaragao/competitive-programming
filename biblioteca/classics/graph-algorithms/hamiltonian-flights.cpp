#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (x).size()
#define pb push_back

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3fll;
const double EPS = 1e-9;
const ll MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;

  vvi adj(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--,v--;
    adj[v].pb(u);
  }


  int sz = (1 << n);
  vvi dp(sz, vi(n, 0));
  dp[1][0] = 1;
  for (int mask = 2; mask < sz; mask++) {
    if((mask & 1)==0) continue;
    if((mask & (1<<(n-1))) and mask != ((1<<n)-1)) continue;

    for(int i=1;i<=n;i++){
      if((mask & (1<<i))==0) continue;

      int prev = mask ^ (1<<i);
      for(auto v : adj[i]){
        if((mask & (1 << v))){
          dp[mask][i] += dp[prev][v];
          dp[mask][i] %= MOD;
        }
      }
    }
  }
  cout << dp[sz - 1][n-1] << endl;

  return 0;
}
