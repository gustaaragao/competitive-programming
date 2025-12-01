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

const int MAXN = 1e5 + 10;
const int INF = 0x3f3f3f3f;

int n, h[MAXN], dp[MAXN];

int c(int i) {
    if (i == 0) return dp[i] = 0;
    if (dp[i] != -1) return dp[i];
    
    int ret = INF;
    if (i - 1 >= 0) {
        ret = min(ret, c(i-1) + abs(h[i] - h[i-1]));
    }
    if (i - 2 >= 0) {
        ret = min(ret, c(i-2) + abs(h[i] - h[i-2]));
    }
    return dp[i] = ret;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++) cin >> h[i];
    cout << c(n-1) << endl;
}
