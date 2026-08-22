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
const double eps = 1e-9;
const ll MOD = 1e9 + 7;

bool cmp(int x, int y){
    cout << "? " << x << " " << y << endl;
    cout.flush() << endl;
    string resp; cin >> resp;
    return resp=="YES";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  vi a(n+1);
  for(int i=1;i<=n;i++) a[i]=i;
  stable_sort(a.begin()+1, a.end(), cmp);
  vi ans(n+1);
  for(int i=1;i<=n;i++) ans[a[i]]=i;

  cout << "!";
  for(int i=1;i<=n;i++){
      cout << " " << ans[i];
  }
  cout << endl;
  cout.flush();

  return 0;
}
