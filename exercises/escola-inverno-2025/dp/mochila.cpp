#include <bits/stdc++.h>
using namespace std;

#define MAXN 100
#define MAXW 100000

#define ll long long

ll values[MAXN], weights[MAXW];
ll dp[MAXN+1][MAXW+1];
ll visited[MAXN+1][MAXW+1];

ll n, w;

ll solve(ll i, ll j) {
    if (i == n || j == w) return 0;
    if (visited[i][j]) return dp[i][j];

    visited[i][j] = true;
    ll ans = solve(i + 1, j);
    if (j + weights[i] <= w) {
        ans = max(ans, values[i] + solve(i + 1, j + weights[i]));
    }
    dp[i][j] = ans;
    return dp[i][j];
}

int main() {
    cin >> n >> w;
    for (ll i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    }

    cout << solve(0, 0) << endl;

    return 0;
}