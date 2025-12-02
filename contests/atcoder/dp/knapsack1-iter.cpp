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

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, w_max; cin >> n >> w_max;
    vector<int> w(n+1), v(n+1);
    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
    vector<vector<int>> dp(n+1, vector<int>(w_max+1, 0LL));
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w_max; j++) {
            if (i == 0 or j == 0) dp[i][j] = 0;
            else {
                // Possibilidade 1: Não colocar i na mochila
                dp[i][j] = dp[i-1][j];
                // Possibilidade 2: Colocar i na mochila
                if (j - w[i] >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]); // dp[i-1][j-w[i]] -> estado sem o item i
                }
            }
        }
    }
    cout << dp[n][w_max] << endl;
}
