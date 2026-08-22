#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;

int dp[MAXN];

int solve(int n) {
    if (n == 0) return dp[0] = 1;
    if (n == 1) return dp[1] = 2;
    return dp[n] = (2 * solve(n-1)) % MOD;
}

signed main() {
	int n; cin >> n;
    cout << solve(n) << endl;
}
