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

const int MINV=1;
const int MAXV=1e9+5;

struct Node {
  int sum;
  Node *l, *r;
  Node(): sum(0), l(nullptr), r(nullptr){}
};

void update(Node* &node, int l, int r, int idx, int val){
  if(!node) node = new Node();

  if(l==r){
    node->sum += val;
    return;
  }

  int m= (l+r)/2;
  if(idx<=m){
    update(node->l, l,m,idx,val);
  }else update(node->r, m+1,r,idx,val);

  int leftSum = node->l ? node->l->sum : 0;
  int rightSum = node->r ? node->r->sum : 0;

  node->sum = leftSum + rightSum;
}

int query(Node* node, int l, int r, int ql, int qr){
  if(!node || ql > r || qr <l ) return 0;
  if (ql <= l && r <= qr) return node->sum;

  int m =(l+r)/2;
  return query(node->l, l,m,ql,qr)+query(node->r, m+1,r,ql,qr);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n,q; cin >> n >> q;

  vi v(n);
  Node* root = nullptr;

  for(int i=0;i<n;i++){
    cin >> v[i];
    update(root, MINV, MAXV, v[i],+1);
  }

  while(q--){
    char t; cin >> t;

    if(t=='?'){
      int a,b; cin >> a >> b;
      cout << query(root, MINV, MAXV, a,b) << endl;
    }else{
      int k,x; cin >> k >> x;
      k--;

      update(root, MINV, MAXV, v[k],-1);

      v[k]=x;
      update(root, MINV, MAXV, v[k],+1);
    }
  }

  return 0;
}
