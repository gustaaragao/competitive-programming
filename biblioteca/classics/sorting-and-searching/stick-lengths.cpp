#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;


signed main() {
    int n; cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    ll mn = LLONG_MAX;
    if (n % 2 == 1) {
        ll md = v[n/2], acc = 0;
        for (int i = 0; i < n; i++) {
            acc += llabs(v[i] - md);
        };
        mn = min(acc, mn);
    } else {
        ll md1 = v[n/2], md2 = v[(n/2)-1], acc = 0;
        for (int i = 0; i < n; i++) acc += llabs(v[i] - md1);
        mn = min(acc, mn);
        acc = 0;
        for (int i = 0; i < n; i++) acc += llabs(v[i] - md2);
        mn = min(acc, mn);
    }
    cout << mn << endl;
}
