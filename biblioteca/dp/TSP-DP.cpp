int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
 
  vvi adj(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--,v--;
    adj[v].pb(u);
  }
 
 
  int sz = (1 << n);
  vvi dp(sz, vi(n, 0));
  dp[1][0] = 1;
  for (int mask = 2; mask < sz; mask++) {
    if((mask & 1)==0) continue;
    if((mask & (1<<(n-1))) and mask != ((1<<n)-1)) continue;
 
    for(int i=1;i<=n;i++){
      if((mask & (1<<i))==0) continue;
 
      int prev = mask ^ (1<<i);
      for(auto v : adj[i]){
        if((mask & (1 << v))){
          dp[mask][i] += dp[prev][v];
          dp[mask][i] %= MOD;
        }
      }
    }
  }
  cout << dp[sz - 1][n-1] << endl;
 
  return 0;
}
// TSP
