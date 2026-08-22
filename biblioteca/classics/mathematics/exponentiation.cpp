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

ll modpow(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;

        base = (base * base) % mod;

        exp /= 2;
    }
    return res;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  while(n--){
    int a,b; cin >> a >> b;
    if(a==0&&b==0){
      cout << 1 << endl;
      continue;
    }
    cout << modpow(a,b,MOD) << endl;
  }
  return 0;
}
