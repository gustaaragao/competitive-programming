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
    int sum_v = 0LL;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
        sum_v += v[i];
    }
    // dp[i][s] -> com os i primeiros itens, o menor peso total para formar o valor total s. 
    vector<vector<int>> dp(n+1, vector<int>(sum_v+1, 1e18));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int s = 0; s <= sum_v; s++) {
            // Possibilidade 1: Não colocamos o item i
            dp[i][s] = dp[i-1][s];
            // Possibilidade 2: Colocamos o item i
            if (s - v[i] >= 0) {
                dp[i][s] = min(dp[i][s], dp[i-1][s-v[i]] + w[i]);
            }
        }
    }
    int ans = 0LL;
    for (int s = sum_v; s >= 0; s--) {
        if (dp[n][s] <= w_max) {
            ans = s;
            break;
        }
    }
    cout << ans << endl;
}
