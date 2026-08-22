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
  int n,x; cin >> n >> x;
  vi a(n);
  for(int i=0;i<n;i++) cin >> a[i];

  vi p(n+1);
  p[0]=0;
  for(int i=1;i<=n;i++){
    p[i] = p[i-1]+a[i-1];
  }

    map<int,int> mp;
    int sum=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        sum += a[i-1];
        if(p[i]==x)ans++;
        int need=p[i]-x;
        ans += mp[need];
        mp[sum]++;
    }


  cout << ans << endl;

  return 0;
}
