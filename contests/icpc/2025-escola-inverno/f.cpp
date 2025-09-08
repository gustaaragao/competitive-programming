#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pi;

const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define MAXN 100000

ll dp[MAXN + 1];
ll a, b;

ll fib(ll k) {
    if (dp[k] != -1) return dp[k];

    return dp[k] = (fib(k - 1) + 1) ^ fib(k - 2); 
}

int main(){ _
    fill(dp, dp + (MAXN + 1), -1); // std::fill(start, end, value)

    int k; 
    cin >> a >> b >> k;
    
    dp[1] = a;
    
    dp[2] = b;
    cout << fib(k) << endl;

    return 0;
}