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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3fll;
const double eps = 1e-9;
const ll MOD = 1e9 + 7;

const int N = 5e3+5;
int dp[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string n,m;
  cin >> n >> m;

  for(int i=0;i<=sz(n);i++) dp[i][0]=i;
  for(int j=0;j<=sz(m);j++) dp[0][j]=j;

  for(int i=1;i<=(int)n.size();i++){
      for(int j=1;j<=(int)m.size();j++){
          if(n[i-1] == m[j-1]){
              dp[i][j] = dp[i-1][j-1];
          }else{
              dp[i][j] = 1 + min({
                      dp[i][j-1],
                      dp[i-1][j],
                      dp[i-1][j-1]});
          }
      }
  }

  cout << dp[sz(n)][sz(m)] << endl;

  return 0;
}
