#include <bits/stdc++.h>

#define nl '\n'
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vl vector<ll>
#define vvl vector<vl>
#define vll vector<pll>
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define sz(x) ((int) x.size())

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less_equal<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_multiset;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INF = 1e9;
const ll P = 13;
const ll M = 1e9 + 7;
const ll MAX = 2e5 + 5;
const ll MAXN = 3e5 + 5;
const ll MAXT = 1e2 + 5;
const ll MAXK = 1e6 + 5;
const ll K = 26;

ll n, m, k, q, x, y, s;

//vector<vl> g;
//vl vis;
//vector<vector<pll>> g;

//vector<ll> primes;
//ll is_prime[MAXN];

void solve(ll tt, ll ti) {
    string s; cin >> s;
    n = s.size();

    vl dp(n+1), pref(n+1);
    dp[0] = pref[0] = 1;

    vl lst(26);
    for (ll i = 1; i <= n; i++) {
        if (lst[s[i-1]-'a'] == 0) {
            dp[i] = pref[i-1];
        } else {
            dp[i] = (pref[i-1] - pref[lst[s[i-1]-'a'] - 1] + M) % M;
        }
        pref[i] = (pref[i-1] + dp[i]) % M;
        lst[s[i-1]-'a'] = i;
    }
    cout << (pref[n]-1+M)%M << nl;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	//cin >> t;

	for (int i = 1; i <= t; i++) {
		solve(t, i);
	}

	return 0;
}
