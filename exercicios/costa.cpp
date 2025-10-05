#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std; using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int ,int> pi;

#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << ' = ' << x << endl

template <class T>
using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = 1e3 + 10;

int m, n;
char mat[MAXN][MAXN];

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == '.') continue;
            else {
                bool ok = false;
                if (i == 0 || mat[i-1][j] == '.') {
                    ok = true;
                }
                else if (i == m - 1 || mat[i+1][j] == '.') {
                    ok = true;
                }
                else if (j == 0 || mat[i][j-1] == '.') {
                    ok = true;
                }
                else if (j == n - 1 || mat[i][j+1] == '.') {
                    ok = true;
                }
                if (ok) ans++;
            }
        }
    }
    cout << ans << endl;
}