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

const int MX = 1e6 + 1;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, x;
  cin >> n >> x;
  vi a(n);
  for (auto &x : a)
    cin >> x;

  vi dp(MX,0);
  dp[0]=1;
  for(int i=0;i<n;i++){
    for(int j = 0; j<=x;j++){
      if(j - a[i] >= 0){
        dp[j] += dp[j-a[i]];
        dp[j] %=MOD;
      }
    }
  }

  cout << dp[x]<<endl;
  return 0;
}
