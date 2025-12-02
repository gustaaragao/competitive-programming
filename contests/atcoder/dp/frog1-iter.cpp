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
    vector<int> h(n+1);
    for (int i = 1; i <= n; i++) cin >> h[i];
    
    vector<int> dp(n+1, 0);
    dp[1] = 0; // Caso Base
    for (int i = 2; i <= n; i++) {
        dp[i] = 1e9;
        if (i - 1 > 0) 
            dp[i] = min(dp[i], dp[i-1] + abs(h[i] - h[i-1]));
        if (i - 2 > 0)
            dp[i] = min(dp[i], dp[i-2] + abs(h[i] - h[i-2]));
    }
    cout << dp[n] << endl;
}
