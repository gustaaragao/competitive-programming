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

  int t = 1;
  while (t--) {
    int n;
    cin >> n;
    int total = (n * (n + 1)) / 2;
    if (total % 2 != 0)
      cout << 0 << endl;
    else {
      int mx = total / 2;
      int dp[mx + 1];
      fill(dp, dp + mx + 1, 0);
      dp[0] = 1;
      for (int i = 1; i <= n; i++) {
        for (int j = mx; j >= 0; j--) {
          if (dp[j] > 0) {
            if (j + i <= mx) {
              dp[j + i] = (dp[j + i] + dp[j]) % MOD;
            }
          }
        }
      }
      cout << (dp[mx] * 500000004) % MOD << endl;
    }
  }

  return 0;
}
