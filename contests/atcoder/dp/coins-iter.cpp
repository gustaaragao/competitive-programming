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
    int n; cin >> n;
    vector<double> p(n+1);
    for (int i = 1; i <= n; i++) cin >> p[i];    
    // dp[i][k] -> probabilidade de se obter k caras após jogar i moedas
    vector<vector<double>> dp(n+1, vector<double>(n+1, 0.0)); 
    // Caso base: 0 moedas e 0 caras -> prob. = 100%
    dp[0][0] = 1.0;
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k <= i; k++) {
            // Possibilidade 1: Joga a moeda i e tira uma coroa
            dp[i][k] += dp[i-1][k] * (1 - p[i]);
            // Possibilidade 2: Joga a moeda i e tira uma cara
            if (k > 0)
                dp[i][k] += dp[i-1][k-1] * p[i];
        }
    }
    double ans = 0.0;
    for (int k = n / 2 + 1; k <= n; k++) {
        ans += dp[n][k];
    }
    cout << fixed << setprecision(9) << ans << endl;
}