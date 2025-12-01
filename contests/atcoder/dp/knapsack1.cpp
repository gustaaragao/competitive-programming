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

const int MAXN = 1e2 + 10, MAXW = 1e5 + 10;
const int INF = 0x3f3f3f3f3f3f3f3fll;

int n, w_max, v[MAXN], w[MAXN], dp[MAXN][MAXW];

int solve(int i, int limit) {
    // Chegou no fim do array ou chegou no limite
    if (i == n or !limit) return dp[i][limit] = 0;
    // Já foi calculado?
    if (dp[i][limit] != -1) return dp[i][limit];
    // Possibilidade 1: Não adicionar o elemento i
    dp[i][limit] = solve(i+1, limit);
    // Possibilidade 2: Adicionar o elemento i
    if (limit >= w[i]) {
        // Máximo entre o valor já calculado e a segunda possibilidade
        dp[i][limit] = max(dp[i][limit], solve(i+1, limit - w[i]) + v[i]);
    }
    return dp[i][limit];
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n >> w_max;
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
    cout << solve(0, w_max) << endl;
}