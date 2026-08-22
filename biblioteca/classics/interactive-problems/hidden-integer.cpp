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

string check(int m){
    cout << "? "<< m << endl;
    cout.flush();
    string response;
    cin >> response;
    return response;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int l=1,r=1e9;
  int ans=0;
  while(l<=r){
      int m = l+(r-l)/2;
      if(check(m)=="YES"){
          l=m+1;
      }else{
          ans=m;
          r=m-1;
      }
  }
  cout << "! " << ans << endl;
  cout.flush();

  return 0;
}
