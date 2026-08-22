#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;
using ll = long long;

vector<ll> songs;
vector<ll> prev_ind;
map<ll, ll> ind;

int main() {
    ll n;
    cin >> n;
    songs.resize(n);
    prev_ind.resize(n, -1);

    for (ll i = 0; i < n; i++) {
        cin >> songs[i];
        if (ind.count(songs[i])) prev_ind[i] = ind[songs[i]];
        ind[songs[i]] = i;
    }

    ll i = 0;
    ll j = 0;
    ll ans = 0;

    while (i < n && j < n) {
        if (prev_ind[j] >= i) {
            i = prev_ind[j] + 1;
        } else {
            ans = max(ans, j - i + 1);
            j++;
        }
    }

    cout << ans << endl;

    return 0;
}
