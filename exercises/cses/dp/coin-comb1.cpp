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

#define MAX_N 1000000
#define MAX_X 1000000

ll dp[MAX_X + 1];
vector<ll> coins;

// dp[n] = sum{i pertence coins, n - 1 >= 0} dp[n - i]
ll solve(ll sum) {
    for (int i = 1; i <= sum; i++) {
        for (auto c : coins) {
            if (i - c < 0) break;
            dp[i] = (dp[i] + (dp[i - c])) % MOD;
        }
    }

    return dp[sum];
}

signed main(){ _

    int n, x; cin >> n >> x;
    for (int i = 0; i < n; i++) {
        ll new_value; cin >> new_value;
        coins.push_back(new_value);
    }
    
    sort(all(coins));

    dp[0] = 1;

    cout << solve(x) << endl;
}