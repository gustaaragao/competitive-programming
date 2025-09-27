#include <bits/stdc++.h>
using namespace std; 

#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pi;

const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    sort(all(v));
    vector<int> diff;
    for (int i = 0, j = 1; i < n && j < n; i=j+1, j=i+1) {
        diff.pb(abs(v[i] - v[j]));
    }
    int ans = 0;
    for (auto x : diff) ans = max(ans, x);
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc;
    while (tc--) solve();
}