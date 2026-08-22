#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;
using ll = long long;

ll ans = 0;
multiset<ll> m;

int main() {
    ll n;
    cin >> n;

    for (ll i = 0; i < n; i++) {
        ll x; cin >> x;
        auto it = m.upper_bound(x);
        // cout << i << endl;
        if (it != m.end()) {
            // cout << "ERASE: " << *(it) << endl;
            m.erase(it);
        } else {
            ans++;
        }
        // cout << x << endl;
        m.insert(x);
    }
    cout << ans << endl;

    return 0;
}
