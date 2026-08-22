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
const int LOG = 31;

int t[N];
int anc[N][LOG];
vb vis;


void bl(int n){
  for(int k=1;k<LOG;k++){
    for(int i=0;i<n;i++){
      anc[i][k]= anc[anc[i][k-1]][k-1];
    }
  }
}

int query(int a, int k){

  for(int i=LOG-1;i>=0;i--){
    if((k>>i)&1) {
      a = anc[a][i];
    }
  }

  return a;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n,q; cin >> n >> q;
  vis.assign(n,false);
  for(int i=0;i<n;i++){
    cin >> t[i];
    t[i]--;
    anc[i][0]=t[i];
  }


  bl(n);
  while(q--){
    int x,k; cin >> x >> k;
    x--;
    if(t[x]==x)cout << x+1 << endl;
    else cout << query(x,k)+1 << endl;
  }

  return 0;
}
