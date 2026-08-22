#include <iostream>
#include <set>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll n;
    cin >> n;

    vector<ll> coins(n);
    for (auto &e : coins) cin >> e;

    sort(coins.begin(), coins.end());

    ll res = 1;
    for (auto c : coins) {
        if (c > res) break;
        res += c;
    }

    cout << res << endl;

    return 0;
}
