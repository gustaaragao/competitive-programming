#include <bits/stdc++.h>

using namespace std;

#define _                                                                      \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3fll;

int main() {
  _

      int n,
      m;
  cin >> n >> m;
  multiset<ll> tickets;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    tickets.insert(x);
  }

  vector<ll> t(m);
  for (int i = 0; i < m; i++) {
    cin >> t[i];
  }



  for (int k = 0; k < m; k++) {
    auto it = tickets.upper_bound(t[k]);
    if(it == tickets.begin()) cout << -1 << endl;
    else {
      it--;
      cout << *it << endl;
      tickets.erase(it);
    }
  }


  return 0;
}
