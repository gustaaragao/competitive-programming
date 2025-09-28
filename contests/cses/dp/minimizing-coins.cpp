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

#define MAX_N 1000000

ll dp[MAX_N + 1];
vector<ll> coins;

signed main(){ _
	
	ll n, x; cin >> n >> x;
	for (int i = 0; i < n; i++) {
		ll c; cin >> c;
		coins.pb(c);
	}

	sort(all(coins));

	dp[0] = 0;
	for (int i = 1; i <= x; i++) {
		dp[i] = INT_MAX;
		for (auto c : coins) {
			if (i - c >= 0) {
				dp[i] = min(dp[i], dp[i - c] + 1);
			}
		}
	}

	cout << ((dp[x] == INT_MAX) ? -1 : dp[x]) << endl;
}