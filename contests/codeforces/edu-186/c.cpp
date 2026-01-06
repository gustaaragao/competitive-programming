#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << x << endl

const int MAXN = 5e3 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    for (auto &i : c) cin >> i;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (a[i] < b[j] < c[k]) {
                    bool ok = true;
                    for (int x = 1; x < n; x++) {
                        if (a[(i+x)%n] < b[(j+x)%n] < c [(k+x)%n]) {
                            continue;
                        } else {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        ans++;
                        dbg(i); dbg(j); dbg(k);
                        dbg(ans);
                    }
                }
            }
        }
                }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc; while (tc--) solve();
}