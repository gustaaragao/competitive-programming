#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void solve() {
    int m, a, b, c; cin >> m >> a >> b >> c;
    int r1 = m, r2 = m;
    int ans = 0;
    if (r1 > a) {
        r1 -= a;
        ans += a;
    } else {
        ans += r1;
        r1 = 0;
    }
    if (r2 > b) {
        r2 -= b;
        ans += b;
    } else {
        ans += r2;
        r2 = 0;
    }

    int reaming = r1 + r2;
    if (reaming > c) {
        reaming -= c;
        ans += c;
    } else {
        ans += reaming;
        reaming = 0;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc;
    while (tc--) solve();
}