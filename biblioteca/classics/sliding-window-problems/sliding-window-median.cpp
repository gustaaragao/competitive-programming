#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
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

int n, m;
int a[200010];
multiset<int> up, low;

void ins(int val) {
  int a = *low.rbegin();
  if (a < val) {
    up.insert(val);
    if (sz(up) > m / 2) {
      low.insert(*up.begin());
      up.erase(up.begin());
    }
  } else {
    low.insert(val);
    if (sz(low) > (m + 1) / 2) {
      up.insert(*low.rbegin());
      low.erase(--low.end());
    }
  }
}

void er(int val) {
  if (up.find(val) != up.end())
    up.erase(up.find(val));
  else
    low.erase(low.find(val));
  if (low.empty()) {
    low.insert(*up.begin());
    up.erase(up.begin());
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  low.insert(a[0]);
  for (int i = 1; i < m; i++) ins(a[i]);
  cout << *low.rbegin() << " ";
  for (int i = m; i < n; i++) {
    if (m == 1) {
      ins(a[i]);
      er(a[i - m]);
    } else {
      er(a[i - m]);
      ins(a[i]);
    }
    cout << *low.rbegin() << " ";
  }
  cout << endl;

  return 0;
}
