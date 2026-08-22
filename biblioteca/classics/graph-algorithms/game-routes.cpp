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

const int N = 1e5 + 10;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vvi adj(n + 1);
  vi in(n+1,0);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    in[v]++;
  }

  vi dp(n+1,0);
  vi acc(n+1,0);
  dp[1] = 1;
  queue<int>q;
  q.push(1);
  for(int i=2;i<=n;i++) if(in[i]==0)q.push(i);
  while(!q.empty()){
      int u = q.front(); q.pop();
      for(auto v : adj[u]){
          in[v]--;
          if(in[v] == 0){
              dp[v] = (dp[v]+dp[u] + acc[v])%MOD;
              q.push(v);
          }else acc[v] = (acc[v] + dp[u])%MOD;
      }
  }

  cout << dp[n] << endl;

  return 0;
}
