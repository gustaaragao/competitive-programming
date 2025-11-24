#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int) (x).size()

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s; cin >> s;
    int n = 0LL;
    for (int i = 0; i < 10 and i < sz(s); i++) {
        n = (n*10) + (s[i] - '0');
    }
    // Fatores primos de Y
    map<int, int> mp;
    for (int d = 2; d * d <= n; d++) { // O(sqrt(n))
        while (n % d == 0) {
            mp[d]++;
            n /= d;
        }
    }
    if (n > 1) mp[n]++;
    if (sz(s) > 10) {
        // adicionando x10
        mp[5] += sz(s) - 10;
        mp[2] += sz(s) - 10;
    }
    cout << sz(mp) << endl;
    for (auto [x, cnt] : mp) {
        cout << x << " " << cnt << endl;
    }
}
