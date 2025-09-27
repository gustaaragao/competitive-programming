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
    map<int, int> mp;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    ll ans = 0;
    if (mp[-1] % 2 != 0) {
        ans++;
        mp[0]++;
        mp[-1]--;
    }
    ans += mp[0];
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc;
    while (tc--) solve();
}