#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    vector<int> cnt_s(26, 0), cnt_t(26, 0);
    for (int i = 0; i < n; i++) {
        cnt_s[s[i] - 'a']++;
        cnt_t[t[i] - 'a']++;
    }
    bool ok = true;
    for (int i = 0; i < 26; i++) {
        if (cnt_s[i] != cnt_t[i]) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc; while (tc--) solve();
}
