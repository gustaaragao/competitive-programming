#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    bool found = false;
    int x = 2;
    while ((x <= (int) 1e18) and !found) {
        for (int i = 0; i < n; i++) {
            if (gcd(x, arr[i]) == 1) {
                found = true;
                break;
            }
        }  
        if (!found) x++;
    }
    if (found) {
        cout << x << endl;
    } else {
        cout << -1 << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc; while (tc--) solve();
}
