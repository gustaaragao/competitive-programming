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

int n; string s;

void solve(){
    cin >> s; n = s.size();
    vector<int> vr;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') vr.pb(i+1);
    }
    if (vr.empty()) {
        cout << n+1 << endl;
        return;
    }
    vector<int> d;
    int ant = 0;
    for (auto i : vr) {
        d.pb(i - ant);
        ant = i;
    }
    d.pb((n + 1) - ant);
    int ans = 0;
    for (auto x : d) ans = max(ans, x);
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc; while (tc--) solve();
}