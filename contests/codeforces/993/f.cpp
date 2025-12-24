#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MAXN = 2e5 + 10;

int grid[MAXN][MAXN];

void solve() {
    int n, m, q; cin >> n >> m >> q;
    vector<int> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = a[i]*b[j];
        }
    }
    vector<int> sum_row(n, 0), sum_col(m, 0);
    
    for (int i = 0; i < n; i++) {
        sum_row[i] = accumulate(grid[i], grid[i]+m, 0);
    }
    for (int j = 0; j < m; j++) {
        int s = 0;
        for (int i = 0; i < n; i++) {
            s += grid[i][j];
        }
        sum_col[j] = s;
    }

    while (q--) {

    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc;
    while (tc--) solve();
}