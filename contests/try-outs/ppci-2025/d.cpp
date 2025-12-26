#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define sz(x) (int) (x).size()

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m, l; cin >> n >> m >> l;
    vector<int> f(m); for (auto &x : f) cin >> x;
    vector<int> c(n); for (auto &x : c) cin >> x;
    
    int cur = 0LL, ans = LLONG_MAX;
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x = c[i] - 1; // 1-INDEX -> 0-INDEXED
        cur += f[x] * (1LL << cnt[x]);
        cnt[x]++;

        if (i >= l) { // remove o c[i-l]
            int y = c[i-l] - 1;
            cur -= f[y] * (1LL << (cnt[y]-1));
            cnt[y]--;
        }

        if (i >= l - 1) {
            ans = min(ans, cur);
        }
    }
    cout << ans << endl;
}