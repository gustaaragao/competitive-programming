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

int const N = 1e6+1;
int fat[N];

ll modpow(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int inv_modular(int n){
  return modpow(n,MOD-2);
}

void fatorial(){
  fat[0]=1;
  for(int i=1;i<N;i++){
    fat[i] = (fat[i-1]*i)%MOD;
  }
}


signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  fatorial();
  int t; cin >> t;
  while(t--){
    int a,b; cin >> a >> b;
    int c=fat[a-b];
    a=fat[a];
    b=fat[b];
    int ans = a;
    ans = (ans*inv_modular(b))%MOD;
    ans = (ans*inv_modular(c))%MOD;
    cout << ans << endl;
  }

  return 0;
}
