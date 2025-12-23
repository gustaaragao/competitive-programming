#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    int sum = 0LL;
    for (int i = 0; i < n - 1; i++) {
        sum += abs(arr[i] - arr[i+1]);
    }
    int best = 0;
    best = max(best, abs(arr[0] - arr[1]));
    best = max(best, abs(arr[n-2] - arr[n-1]));
    for (int i = 1; i < n - 1; i++) {
        // eco = antes com k - depois de remover o k
        int eco = abs(arr[i-1] - arr[i]) 
                + abs(arr[i] - arr[i+1])
                - abs(arr[i-1] - arr[i+1]);
        best = max(best, eco);
    }
    cout << sum - best << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc;
    while (tc--) solve();
}