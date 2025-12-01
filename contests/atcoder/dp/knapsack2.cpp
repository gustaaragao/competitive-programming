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

const int MAXN = 1e2 + 10;
const int MAXV = 1e5 + 10; // 1 <= vi <= 1e3 e 1 <= N <= 1e2

int n, w_max, sum_v, w[MAXN], v[MAXN], dp[MAXN][MAXV];
/*
Normalmente queremos maximizar a soma de v[] a partir de uma limitação de soma de w[] <= w_max

Podemos pensar no mesmo problema como, qual o menor peso possível que podemos colocar na mochila
tal que atinge a soma de valores s.

Em si, vamos percorrer na dp[n][s] procurando a soma S máxima que podemos construir.
*/
int solve(int i, int s) {
    if (s == 0) return dp[i][s] = 0;
    if (i == n) return dp[i][s] = (int) 1e18;
    if (dp[i][s] != -1) return dp[i][s];
    // Possibilidade 1: Não adicionar o item i
    dp[i][s] = solve(i+1, s);
    if (s >= v[i]) {
        // Possibilidade 2: Adicionar o item i
        dp[i][s] = min(dp[i][s], solve(i+1, s-v[i]) + w[i]);
    }
    return dp[i][s];
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n >> w_max;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
        sum_v += v[i];
    }
    for (int s = 0; s <= sum_v; s++) solve(0, s);
    int ans = -1;
    for (int s = sum_v; s >= s; s--) {
        if (dp[0][s] <= w_max) {
            ans = s;
            break;
        }
    }
    cout << ans << endl;
}