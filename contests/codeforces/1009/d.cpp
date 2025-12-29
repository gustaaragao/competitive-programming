#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n); 
    for (auto &i : a) cin >> i;
    vector<int> r(n); 
    for (auto &i : r) cin >> i;

    /*
    (0, 0)
    (1, 1) (-1, -1) (-1, 1) (1, -1)
    (1, 0) (-1, 0)
    (0, 1) (0, -1)
    (2, 0) (-2, 0)
    (0, 2) (0, -2)
    */

}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc; while(tc--) solve();
}