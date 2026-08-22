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

int dp[100005][105];

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;

  vi a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (a[0] == 0) {
    fill(dp[0], dp[0] + 101, 1);
  } else {
    dp[0][a[0]] = 1;
  }
  for (int i = 1; i < n; i++) {
    if (a[i] != 0) {
      dp[i][a[i]] += dp[i - 1][a[i]];
      if (a[i] - 1 > 0)
        dp[i][a[i]] += dp[i - 1][a[i] - 1];
      if (a[i] + 1 <= m)
        dp[i][a[i]] += dp[i - 1][a[i] + 1];
      dp[i][a[i]] %= MOD;
    } else {
      for (int j = 1; j <= m; j++) {
        dp[i][j] += dp[i - 1][j];
        if (j - 1 > 0)
          dp[i][j] += dp[i - 1][j - 1];
        if (j+ 1 <= m)
          dp[i][j] += dp[i - 1][j + 1];
        dp[i][j]%=MOD;
      }
    }
  }
  int ans=0;
  for(int i=1;i<=m;i++){
    ans = (ans + dp[n-1][i])%MOD;
  }
  cout << ans << endl;

  return 0;
}
