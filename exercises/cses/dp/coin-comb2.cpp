#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pi;

const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define MAX_N 100
#define MAX_X 1000000

// Recorrência: dp[i][j] = dp[i - 1][j] + dp[i][j - c[i]]

// +2 pois é +1 por causa do mapeamento e o outro +1 é por causa da coluna 0
ll dp[MAX_N + 1][MAX_X + 2];

vector<ll> coins;

ll solve(int i, int j) { // i -> moeda, j -> soma
    if (i < 0 || j < 0) return 0;
    
    // "Quando eu preciso chegar na soma 0 basta fazer nada (1 forma)"
    if (j == 0) return 1;

    if (dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = (solve(i - 1, j) + solve(i, j - coins[i])) % MOD;
}

signed main(){ _
    int n, x; cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int new_value; cin >> new_value;
        coins.pb(new_value);
    }
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = -1;
        }
    }
    cout << solve(n - 1, x) << endl;
}