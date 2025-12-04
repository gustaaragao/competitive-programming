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

const int MAX = 3e3 + 10;

int n;
bool vis[MAX][MAX];
double p[MAX], dp[MAX][MAX];

// i -> estado, k -> moedas
double solve(int i, int k) {
    // Casos bases
    if (vis[i][k]) return dp[i][k];
    vis[i][k] = true;

    // 0 moedas lançadas
    if (i == 0) {
        // Ter 0 caras -> Probabilidade de 100%
        if(k == 0) return dp[i][k] = 1;
        else return dp[i][k] = 0; // Ter k > 0 caras -> Impossível -> 0%
    }

    double ret = 0.0;
    // Possibilidade 1: Joguei a moeda i e tirei uma cara
    if (k > 0) ret += p[i] * solve(i-1, k-1); 
    // Possibilidade 2: Joguei a moeda i e tirei uma coroa
    ret += (1 - p[i]) * solve(i-1, k);
    return dp[i][k] = ret;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    double ans = 0.0;
    for (int k = (n / 2) + 1; k <= n; k++) {
        ans += solve(n, k);
    }
    cout << fixed << setprecision(9) << ans << endl;
}
