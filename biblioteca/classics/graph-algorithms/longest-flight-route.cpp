#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
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
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3fll;
const double eps = 1e-9;
const ll MOD = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m; cin >> n >> m;
  vvi adj(n+1);
  vi indg(n+1,0);
  for(int i=0;i<m;i++){
    int u,v; cin >> u >> v;
    adj[u].pb(v);
    indg[v]++;
  }

  vi dist(n+1,-1);
  vi par(n+1,-1);
  dist[1]=0;
  queue<int> q;
  for(int i=1;i<=n;i++) if(indg[i]==0) q.push(i);

  while(!q.empty()){
    int u=q.front();q.pop();
    for(auto v : adj[u]){
      if(dist[u] != -1 and dist[v]<dist[u]+1){
        par[v]=u;
        dist[v]=dist[u]+1;
      }
      indg[v]--;
      if(indg[v]==0){
        q.push(v);
      }
    }
  }

  if(dist[n]==-1){
    cout << "IMPOSSIBLE"<<endl;
    return 0;
  }

  vi ans;
  int cur=n;
  while(cur!=-1){
    ans.pb(cur);
    cur=par[cur];
  }

  cout << sz(ans)<<endl;
  reverse(all(ans));
  for(auto x : ans){
    cout << x << " ";
  }
  cout << endl;

  return 0;
}
