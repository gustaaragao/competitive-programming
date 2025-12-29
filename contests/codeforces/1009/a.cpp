#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second

void solve() {
    int l, r, d, u; cin >> l >> r >> d >> u;
    if ((r == l) and (l == u) and (u == d)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc; while(tc--) solve();
}