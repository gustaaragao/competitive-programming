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
    vector<vector<int>> v(3, vector<int>(n+1));
    for (int i = 1; i <= n; i++) {
        cin >> v[0][i] >> v[1][i] >> v[2][i]; 
    }
    vector<vector<int>> dp(3, vector<int>(n+1, 0));
    // dp[i][k] -> soma de felicidade ao jogar i no dia k
    for (int i = 0; i < 3; i++) dp[i][1] = v[i][1]; // Caso base
    for (int k = 2; k <= n; k++) {
        for (int i = 0; i < 3; i++) {
            dp[i][k] = -1e9;
            for (int j = 0; j < 3; j++) { // testando as jogadas possíveis do dia anterior
                if (j != i) {
                    dp[i][k] = max(dp[i][k], dp[j][k-1] + v[i][k]);
                }
            }
        }
    }
    cout << max({dp[0][n], dp[1][n], dp[2][n]}) << endl;
}
