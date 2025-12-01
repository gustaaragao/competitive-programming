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

const int MAXN = 1e5 + 10;

int n, v[3][MAXN], dp[3][MAXN];

// i -> ['a','b','c'] -> [0, 1, 2] -> o evento 'i' que vamos escolher no dia 'j'
int solve(int i, int j) {
    if (j == 0) return dp[i][j] = v[i][j];
    if (dp[i][j] != -1) return dp[i][j];
    int ret = -1e9;
    for (int k = 0; k < 3; k++) {
        if (k != i) {
            ret = max(ret, solve(k, j - 1) + v[i][j]);
        }
    }
    return dp[i][j] = ret;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[0][i] >> v[1][i] >> v[2][i];
    }
    for (int i = 0; i < 3; i++) solve(i, n-1);
    cout << max({dp[0][n-1], dp[1][n-1], dp[2][n-1]}) << endl;
}
