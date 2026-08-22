#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    map<ll, ll> mp;

    for (auto &e : a) cin >> e;

    for (ll i = 0; i < n; i++) {
        mp[a[i]] = i;
    }

    ll ans = 1;
    for (ll i = 1; i < n; i++) {
        if (mp[i + 1] < mp[i]) ans++;
    }

    cout << ans << endl;
    return 0;
}
