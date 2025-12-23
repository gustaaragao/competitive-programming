#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;    
    
    int mn = *min_element(arr.begin(), arr.end());
    int min_diff = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        if (arr[i] > mn) {
            min_diff = min(min_diff, arr[i] - mn);
        }
    }
    int ans = max(mn, min_diff);
    cout << ans << endl;    
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc;
    while (tc--) solve();
}