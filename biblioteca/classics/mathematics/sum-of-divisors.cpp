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

int inv(int a) {
    return a <= 1 ? a : MOD - (long long)(MOD/a) * inv(MOD % a) % MOD;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int r=0;
  int ans=0;
  int inv2 = inv(2);
  for(int i=1;i<=n;i=r+1){
    int d = n/i;
    r = n/d;
    int pa = ((((i+r)%MOD)
    *((r-i+1)%MOD))
    %MOD)
    *inv2
    %MOD;
    int cont = (pa*(d%MOD))%MOD;
    ans = (ans+cont)%MOD;
  }
  cout << ans << endl;
  return 0;
}
