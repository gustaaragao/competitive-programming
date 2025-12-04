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

const int MAX = 1e3 + 5;
const int MOD = 1e9 + 7;

int h, w; 
char grid[MAX][MAX];

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> dp(h+1, vector<int>(w+1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i+1 < h and grid[i+1][j] != '#') 
                dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % MOD;
            if (j+1 < w and grid[i][j+1] != '#') 
                dp[i][j+1] = (dp[i][j+1] + dp[i][j]) % MOD;
        }
    }
    cout << dp[h-1][w-1] << endl;
}
