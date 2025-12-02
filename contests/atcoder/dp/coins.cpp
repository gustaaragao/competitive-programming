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

const int MAXN = 3e4 + 10;

int n;
double p[MAXN];
vector<vector<double>> dp(MAXN, vector<double>(MAXN, -1));
// dp[i][j] -> probabilidade de com as i primeiras moedas fazer j caras

double solve(int i, int j) {
    // Casos bases?
    if (i == n) return dp[i][j] = 1;
    if (dp[i][j] != -1) return dp[i][j];

    // Possibilidade 1: lançar a moeda i e cair coroa
    // Possibilidade 2: lançar a moeda i e cair cara
    dp[i][j] += (1 - p[i]) * solve(i-1, j) + p[i] * solve(i, j-1);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n; 
    for (int i = 0; i < n; i++) cin >> p[i];
    solve(0, n);
}
