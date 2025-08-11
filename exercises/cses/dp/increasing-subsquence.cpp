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

int lis(const vector<int> &a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> dp(n + 1, INF);

    dp[0] = -INF;

    for (int i = 0; i < n; i++) {
        int l = upper_bound(all(dp), a[i]) - dp.begin();
        if (dp[l - 1] < a[i] && a[i] < dp[l]) {
            dp[l] = a[i];
        }
    }

    int ans = 0;
    for (int l = 0; l <= n; l++) {
        if (dp[l] < INF) ans = l;
    }
    return ans;
}

signed main(){ _

    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    cout << lis(a) << endl;
}