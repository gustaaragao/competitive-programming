#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define sz(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << x << endl

void solve() {
    int x, y, k; cin >> x >> y >> k;
    int tx = (x + k - 1) / k;
    int ty = (y + k - 1) / k;
    if (ty >= tx) {
        cout << 2 * ty << endl;
    } else {
        cout << 2 * tx - 1 << endl;
    }
}


/*
9 / 3 = 3
11 / 3 = 4

0 / 8 = 0
10 / 8 = 2

10^6 / 10 = 10^5
10^5 / 10 = 10^4
*/

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc; while(tc--) solve();
}