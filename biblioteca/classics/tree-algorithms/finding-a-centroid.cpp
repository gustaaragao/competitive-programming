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

const int N = 2e5+10;

vi adj[N];
int sz[N];
int tot=0;

void dfs(int u, int p){
  tot++;
  sz[u]=1;
  for(auto v : adj[u]) if(v!=p){
    dfs(v,u);
    sz[u]+=sz[v];
  }
}

int cent(int u, int p){
  for(auto v : adj[u]){
    if(v==p) continue;
    if(sz[v] > tot/2) return cent(v,u);
  }

  return u;
}

int find_centroid(){
  dfs(1,0);
  return cent(1,0);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for(int i=0;i<n-1;i++){
    int u, v; cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  int ans = find_centroid();

  cout << ans << endl;

  return 0;
}
