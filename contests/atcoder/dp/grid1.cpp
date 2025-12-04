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

const int MAX = 1e3 + 5;
const int MOD = 1e9 + 7;

int w, h, dp[MAX][MAX];
char grid[MAX][MAX];

int solve(int i, int j) {
    if (i == 0 and j == 0) return dp[i][j] = 1;
    if (grid[i][j] == '#') return dp[i][j] = 0;
    if (dp[i][j] != -1) return dp[i][j];
    int ret = 0;
    if (i-1 >= 0)
        ret = (ret + solve(i-1, j)) % MOD;
    if (j-1 >= 0)
        ret = (ret + solve(i, j-1)) % MOD;
    return dp[i][j] = ret;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> w >> h;
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            cin >> grid[i][j];
        }
    }
    cout << solve(w-1, h-1) << endl;
}
