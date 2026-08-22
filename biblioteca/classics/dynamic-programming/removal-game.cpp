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

const int N = 5e3+1;

int v[N];
vvi dp1(N, vi(N,LINF));
vvi dp2(N, vi(N,LINF));

int solve(int l, int r, bool t){
  if(t){
    if(l==r) return v[l];
    if(dp1[l][r] != LINF) return dp1[l][r];
    return dp1[l][r] = max(v[l] + solve(l+1,r,!t),
        v[r]+ solve(l,r-1,!t));
  }else{
    if(l==r) return 0;
    if(dp2[l][r] != LINF) return dp2[l][r];
    return dp2[l][r] = min(solve(l+1,r,!t), solve(l,r-1,!t));
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for(int i=0;i<n;i++) cin >> v[i];

  cout << solve(0,n-1,true) << endl;

  return 0;
}
