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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3fll;
const double eps = 1e-9;
const ll MOD = 1e9 + 7;

ll get_dist(pll a, pll b) {
    return (a.ff - b.ff) * (a.ff - b.ff) + (a.ss - b.ss) * (a.ss - b.ss);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  vector<pll> p(n);
  for(int i=0;i<n;i++) cin >> p[i].ff >> p[i].ss;

  sort(all(p), [](pii a, pii b){
      if(a.ff == b.ff) return a.ss < b.ss;
      return a.ff < b.ff;
      });

  set<pll> st;
  st.insert({p[0].ss, p[0].ff});
  ll min_dist = LLONG_MAX;
  int j=0;
  for(int i=1;i<n;i++){
    ll d = (min_dist == LLONG_MAX) ? 4e9 : sqrt(min_dist) + 1;
    while(j < i and p[j].ff < p[i].ff - d){
      st.erase({p[j].ss, p[j].ff});
      j++;
    }

    auto l = st.lower_bound({p[i].ss - d,-4e9});
    auto r = st.upper_bound({p[i].ss + d, 4e9});

    for(auto it = l; it != r;++it){
      ll dist = get_dist(p[i], {it->ss, it->ff});
      if(min_dist > dist){
        min_dist = dist;
        dist = sqrt(min_dist);
      }
    }
    st.insert({p[i].ss, p[i].ff});
  }
  cout << min_dist << endl;

  return 0;
}
