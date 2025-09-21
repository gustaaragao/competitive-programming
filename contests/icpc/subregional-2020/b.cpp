#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pi;

const ll MOD = 1e9 + 7;

signed main(){ _

    vector<vector<int>> grid(11, vector<int>(11, 0));

    int n; cin >> n;
    while (n--) {
        int d, l, r, c; cin >> d >> l >> r >> c;
        if (d == 0) {
            for (int j = c; j <= c + l - 1; j++) {
                if (j > 10) {
                    cout << "N" << endl;
                    return 0;
                }
                if (grid[r][j] >= 1) {
                    cout << "N" << endl;
                    return 0;
                } else {
                    grid[r][j]++;
                }
            }
        } else {
            for (int i = r; i <= r + l - 1; i++) {
                if (i > 10) {
                    cout << "N" << endl;
                    return 0;
                }
                if (grid[i][c] >= 1) {
                    cout << "N" << endl;
                    return 0;
                } else {
                    grid[i][c]++;
                }
            }
        }
    }
    cout << "Y" << endl;
}