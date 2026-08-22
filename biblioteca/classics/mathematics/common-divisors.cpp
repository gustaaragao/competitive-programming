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

const int N = 1e6;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int mx = 0;
  vi a(n);
  vi freq(N + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    freq[a[i]]++;
  }

  for(int i=N;i>=1;i--){
    int div=0;
    for(int j=i;j<=N;j+=i){
      div += freq[j];
    }

    if(div >1){
      cout << i << endl;
      break;
    }
  }


  return 0;
}
