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

vector<int> suffix_array(string s) {
	s += "$";
	int n = s.size(), N = max(n, 260);
	vector<int> sa(n), ra(n);
	for(int i = 0; i < n; i++) sa[i] = i, ra[i] = s[i];

	for(int k = 0; k < n; k ? k *= 2 : k++) {
		vector<int> nsa(sa), nra(n), cnt(N);

		for(int i = 0; i < n; i++) nsa[i] = (nsa[i]-k+n)%n, cnt[ra[i]]++;
		for(int i = 1; i < N; i++) cnt[i] += cnt[i-1];
		for(int i = n-1; i+1; i--) sa[--cnt[ra[nsa[i]]]] = nsa[i];

		for(int i = 1, r = 0; i < n; i++) nra[sa[i]] = r += ra[sa[i]] !=
			        ra[sa[i-1]] or ra[(sa[i]+k)%n] != ra[(sa[i-1]+k)%n];
		ra = nra;
		if (ra[sa[n-1]] == n-1) break;
	}
	return vector<int>(sa.begin()+1, sa.end());
}

vector<int> kasai(string s, vector<int> sa) {
	int n = s.size(), k = 0;
	vector<int> ra(n), lcp(n);
	for (int i = 0; i < n; i++) ra[sa[i]] = i;

	for (int i = 0; i < n; i++, k -= !!k) {
		if (ra[i] == n-1) {
			k = 0;
			continue;
		}
		int j = sa[ra[i]+1];
		while (i+k < n and j+k < n and s[i+k] == s[j+k]) k++;
		lcp[ra[i]] = k;
	}
	return lcp;
}

void solve(ll tt, ll ti) {
	string s;
	cin >> s;
	cin >> k;
	n = s.size();
	ll cnt = 0;

	vector<int> sa = suffix_array(s);
	vector<int> lcp = kasai(s, sa);

	for (ll i = 0; i < n; i++) {
		if (i == 0) {
			cnt += n - sa[0];
		} else {
			cnt += n - (sa[i] + lcp[i-1]);
		}

		if (cnt >= k) {
			ll len = k, start = sa[i];
			if (i != 0) {
			    ll end = (n-1) - (cnt - k);
				len = end - start + 1;
			}
			cout << s.substr(start, len);
			break;
		}
	}
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
