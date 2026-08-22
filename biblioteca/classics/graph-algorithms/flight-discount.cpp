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

  vector<vpll> g(n);
  for(int i=0;i<m;i++){
    int u,v,w; cin >> u >> v >> w;
    u--,v--;
    g[u].emplace_back(v,w);
  }

  priority_queue<array<ll,3>> q;
  q.push({0,0,0});
  vvl dist(n, vl(2,LINF));
  vector<vb> vis(n, vb(2,false));
  dist[0][0]=0;
  while(!q.empty()){
    auto [w, u,c] = q.top();
    q.pop();
    if(dist[u][c]==LINF or vis[u][c]) continue;
    vis[u][c]=1;
    for(auto [v,cost] : g[u]){
        if(c==0){
            ll cur1=dist[u][c]+cost/2LL;
            ll cur2=dist[u][c]+cost;
            if(cur1<dist[v][1]){
                dist[v][1]=cur1;
                q.push({-cur1, v, 1});
            }
            if(cur2<dist[v][0]){
                dist[v][0]=cur2;
                q.push({-cur2,v,0});
            }
        }else{
            ll cur = dist[u][c]+cost;
            if(cur<dist[v][c]){
                dist[v][c]=cur;
                q.push({-cur,v,1});
            }
        }
    }
  }

  cout<<min(dist[n-1][0], dist[n-1][1])<<endl;

  return 0;
}
