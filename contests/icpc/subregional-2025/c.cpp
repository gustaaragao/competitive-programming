#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n; cin >> n;
    
    ll x = 0;
    for (int i = n; i >= 0; i--) {
        ll bit; cin >> bit;
        x += (bit << i);
    }
    
    ll ans = 0;
    while (x != 1) {
        ans++;
        if (x & 1) {
            x = ((x << 1) ^ x) ^ 1;
        } else {
            x = x >> 1;
        }
    }
    cout << ans << endl;
}