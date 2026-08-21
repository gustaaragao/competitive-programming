const int N = 2e5+5;
vi adj[N];
ll dp[N];
ll sum[N];
ll ans[N];
int s;
 
// Objetive: compute for each node the sum of the distances from the other nodes
// Dfs1: compute depth (dp)
void dfs1(int u, int p){
    sum[u]=1;
    for(auto v : adj[u]) if(v!=p){
        dfs1(v,u);
        dp[u] += dp[v]+sum[v];
        sum[u] += sum[v];
    }
}
 
// DFS2: for each node compute the total sum
// f(x) = sum of parent - dp
void dfs2(int u, int p){
    ans[u] = dp[u];
    for(auto v : adj[u]){
        if(v!=p){
            dp[u] -= dp[v] + sum[v];
            sum[u] -= sum[v];
            
            dp[v] += dp[u] + sum[u];
            sum[v] += sum[u];
            dfs2(v,u);
 
            sum[v] -= sum[u];
            dp[v] -= dp[u] + sum[u];
 
            sum[u] += sum[v];
            dp[u] += dp[v] + sum[v];
 
        }
    }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for(int i=0;i<n-1;i++){
      int u,v; cin >> u >> v;
      adj[u].pb(v);
      adj[v].pb(u);
  }
 
  dfs1(1,0);
 
  dfs2(1,0);
  for(int i=1;i<=n;i++) cout << ans[i] << " ";
  cout << endl;
 
  return 0;
}
