#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define sz(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pi;

const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e5 + 10;

int n, k, h[MAX], dp[MAX];

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> h[i];
    // cost(i) = min(cost(j) + |h[i] - h[j]|) para j >= 0 e i - k <= j <= i - 1 
    // Caso base: dp[0] = 0
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = INF;
        for (int j = i - k; j <= i - 1; j++) {
            if (j >= 0) {
                dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
            }
        }
    }
    cout << dp[n-1] << endl;
}