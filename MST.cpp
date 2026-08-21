// No problema abaixo, pedia para encontrar a Maximum Spanning Tree
// Caso fosse pedido a Minimum Spanning Treee, a diferenca seria no loop i
struct DSU {
  vector<int> par, rnk, sz;
  int c;
  DSU(int n) : par(n + 1), rnk(n + 1, 0), sz(n + 1, 1), c(n) {
    for (int i = 1; i <= n; ++i)
      par[i] = i;
  }
  int find(int i) { return (par[i] == i ? i : (par[i] = find(par[i]))); }
  bool same(int i, int j) { return find(i) == find(j); }
  int get_size(int i) { return sz[find(i)]; }
  int count() { return c; }
  bool merge(int i, int j) {
    if ((i = find(i)) == (j = find(j)))
      return 0;
    else
      --c;
    if (rnk[i] > rnk[j])
      swap(i, j);
    par[i] = j;
    sz[j] += sz[i];
    if (rnk[i] == rnk[j])
      rnk[j]++;
    return 1;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  DSU dsu(n+1);
  vi id(1<<20,0);
  for(int i=1;i<=n;i++){
    int x; cin >> x;
    id[x]=i;
  }

  ll max_w=0;
  for(int i=1e6;i>=1;i--){
    int lst=-1;
    for(int j=i;j<=1e6;j+=i){
        if(id[j]>0){
            if(lst>0 and !dsu.same(lst,id[j])){
                dsu.merge(lst,id[j]);
                max_w+=i;
            }
            lst=id[j];
        }
    }
  }
  cout<<max_w<<endl;

