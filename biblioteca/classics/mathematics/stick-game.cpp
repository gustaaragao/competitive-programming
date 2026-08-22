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
const double eps = 1e-9;
const ll MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n,k; cin >> n >> k;
  vi a(k);
  for(auto &x:a) cin >> x;

  vb dp(n+1,false);
  for(int i=0;i<k;i++) dp[a[i]]=true;

  for(int i=1;i<=n;i++){
    bool flag=false;
    for(int j=0;j<k;j++){
      if(i-a[j] > 0){
        if(!dp[i-a[j]]) flag=true;
      }
    }
    if(flag) dp[i]=true;
  }

  for(int i=1;i<=n;i++){
    if(dp[i]) cout << 'W';
    else cout << 'L';
  }

  return 0;
}
