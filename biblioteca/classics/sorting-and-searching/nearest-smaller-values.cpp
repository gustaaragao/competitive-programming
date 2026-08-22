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

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vi a(n);
  for(auto &x:a)cin>>x;
  stack<pii> st;
  vi ans(n, 0);
  for (int i = 0; i <n; i++) {
    while (!st.empty() and st.top().f >= a[i])
      st.pop();
    if (!st.empty())
      ans[i] = st.top().sec;

    st.push({a[i],i+1});
  }

  for (auto i : ans)
    cout << i << " ";
  cout << endl;

  return 0;
}
