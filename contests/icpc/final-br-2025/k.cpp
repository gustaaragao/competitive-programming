#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define ff first
#define ss second

const int INF = 1e9 + 10;
const int MAX = 1e5 + 10;

int n, k;
pair<int, int> v[MAX];

const pair<int, int> dir[4] = {
    {1, 1},
    {1, -1},
    {-1, 1},
    {-1, -1}
};

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    int min_x = INF, min_y = INF;
    int max_x = -INF, max_y = -INF;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        min_x = min(min_x, x);
        min_y = min(min_y, y);
        max_x = max(max_x, x);
        max_y = max(max_y, y);
        v[i].ff = x; v[i].ss = y;
    }
    int ans = -INF;
    // Estratégia gulosa 1: Levar o rei para quina
    for (int i = 0; i < n; i++) {
        auto [x, y] = v[i];
        for (auto [dx, dy] : dir) {
            int new_x = x + k*dx, new_y = y + k*dy;
            int new_min_x = min(min_x, new_x), new_max_x = max(max_x, new_x);
            int new_min_y = min(min_y, new_y), new_max_y = max(max_y, new_y);
            int larg = new_max_x - new_min_x + 1;
            int alt = new_max_y - new_min_y + 1;
            ans = max(ans, alt*larg);
        }
    }
    int larg = max_x - min_x + 1, alt = max_y - min_y + 1;
    for (int i = 0; i < k; i++) {
        if (larg > alt) alt++;
        else larg++;
    }
    ans = max(ans, larg*alt);
    cout << ans << endl;
}

