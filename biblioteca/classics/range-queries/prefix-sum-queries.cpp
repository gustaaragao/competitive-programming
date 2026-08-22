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

struct Node{
  int prefix,sum;
};

const int N = 2e5+10;

Node seg[N*4];
int v[N];

Node combina(Node a, Node b){
  Node resp;
  resp.prefix = max({a.prefix,a.sum+b.prefix, a.sum+b.sum});
  resp.sum = a.sum+b.sum;
  return resp;
}

Node build(int p, int l, int r){
  if(l==r){
    return seg[p]={v[l],v[l]};
  }
  int m=(l+r)/2;
  return seg[p]=combina(build(2*p,l,m),build(2*p+1,m+1,r));
}

Node update(int i, int x, int p, int l, int r){
  if(i < l or i > r) return seg[p];
  if(l==r){
    v[l]=x;
    return seg[p]={x,x};
  }
  int m=(l+r)/2;
  return seg[p]=combina(update(i,x,2*p,l,m),update(i,x,2*p+1,m+1,r));
}

Node query(int ql, int qr, int p, int l, int r){
  if(ql > r or qr < l) return {0,0};
  if(ql <= l and r <= qr) return seg[p];

  int m=(l+r)/2;
  return combina(query(ql,qr,2*p,l,m),query(ql,qr,2*p+1,m+1,r));
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n,q; cin >> n >> q;
  for(int i=0;i<n;i++) cin >> v[i];

  build(1,0,n-1);
  while(q--){
    int t; cin >> t;
    if(t==1){
      int i,x; cin >> i >> x;
      i--;
      update(i,x,1,0,n-1);
    }else{
      int l,r; cin >> l >> r;
      l--,r--;
      cout << max(0LL,query(l,r,1,0,n-1).prefix) << endl;
    }
  }
  return 0;
}
