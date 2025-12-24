#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> p;
    int f = n-1, s = 1;
    while (f > 0) {
        p.push_back({f, s});
        f--;
        s++;
    }
    cout << (int) p.size() << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc;
    while (tc--) solve();
}