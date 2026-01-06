#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << x << endl

void solve() {
    int a, b; cin >> a >> b;
    int aa = a, bb = b;

    int ans1 = 0;    
    int k = 1;
    bool turn = true;
    // Dark chocolate and white chocolate
    while (aa >= 0 and bb >= 0) {
        if (turn) {
            if (aa >= k) {
                aa -= k;
                k = k << 1;
                ans1++;
            } else {
                break;
            }
        } else {
            if (bb >= k) {
                bb -= k;
                k = k << 1;
                ans1++;
            } else {
                break;
            }
        }
        turn = !turn;
    }
    
    turn = true, aa = a, bb = b, k = 1;

    int ans2 = 0;
    // White chocolate and dark chocolate
    while (aa >= 0 and bb >= 0) {
        if (turn) {
            if (bb >= k) {
                bb -= k;
                k = k << 1;
                ans2++;
            } else {
                break;
            }
        } else {
            if (aa >= k) {
                aa -= k;
                k = k << 1;
                ans2++;
            } else {
                break;
            }
        }
        turn = !turn;
    }
    
    cout << max(ans1, ans2) << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc; while(tc--) solve();
}