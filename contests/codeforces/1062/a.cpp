#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    if (a == b and b == c and c == d) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc; while (tc--) solve();
}
