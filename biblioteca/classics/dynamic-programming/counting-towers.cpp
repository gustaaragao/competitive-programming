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
const double EPS = 1e-9;
const ll MOD = 1e9 + 7;

const int N = 1e6+5;

ll dp1[N], dp2[N];

void preprocess(){
    dp1[0] = dp2[0] = 1;
    for (int i = 1; i < N; i++) {
      dp2[i] = (dp2[i - 1] * 4) + dp1[i - 1];
      dp2[i] %= MOD;
      dp1[i] = (dp1[i - 1] * 2) + dp2[i - 1];
      dp1[i] %= MOD;
    }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  preprocess();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << (dp1[n - 1] + dp2[n - 1]) % MOD << endl;
  }

  return 0;
}
