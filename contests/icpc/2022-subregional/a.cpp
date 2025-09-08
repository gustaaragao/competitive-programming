#include <bits/stdc++.h>

using namespace std;
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0)
typedef pair<int, int> ii;
typedef long long ll;

#define endl '\n'


signed main(void) {
    FAST_IO;

    int n; cin >> n;
    string s; cin >> s;
    ll ans = 0;
    int count_a = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            count_a++;
        } else {
            if (count_a >= 2) ans = ans + count_a;
            count_a = 0;
        }
    }
    if (count_a >= 2) ans = ans + count_a;
    cout << ans << endl;
}