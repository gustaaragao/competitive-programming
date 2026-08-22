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
const ll MOD = 1e9 + 7;
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

ll bp(ll a, ll b, ll MOD) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res*a%MOD;
        b /= 2;
        a = a*a%MOD;
    }
    return res;
}

ll inverse(ll x, ll MOD) {
    return bp(x, MOD-2, MOD);
}

template<int MOD>
struct Bit {
	int n;
	vector<ll> bit;
	Bit(int _n=0) : n(_n), bit(n + 1) {}
	Bit(vector<ll> v) : n(v.size()), bit(n + 1) {
		for (int i = 1; i <= n; i++) {
			bit[i] = (bit[i] + MOD + v[i - 1])%MOD;
			int j = i + (i & -i);
			if (j <= n) bit[j] = (bit[j]+MOD+bit[i])%MOD;
		}
	}
	void update(int i, ll x) { // soma x na posicao i
		for (i++; i <= n; i += i & -i) bit[i] = (bit[i] + x + MOD)%MOD;
	}
	ll pref(int i) { // soma [0, i]
		ll ret = 0;
		for (i++; i; i -= i & -i) ret = (ret+bit[i]+MOD)%MOD;
		return ret;
	}
	ll query(int l, int r) {  // soma [l, r]
		return (pref(r) - pref(l - 1)+MOD)%MOD;
	}
};

int uniform(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

template<int MOD> struct str_hash {
	static int P;
	vector<ll> h, p, inv;
	string s;
	int n;
	Bit<MOD> *bit = nullptr;
	str_hash(string s) : h(s.size()), p(s.size()), s(s) {
	    n = s.size();
		p[0] = 1, h[0] = s[0];
		inv.resize(n);

		for (int i = 1; i < s.size(); i++) {
		    p[i] = p[i - 1]*P%MOD, h[i] = p[i]*s[i] % MOD;
		}

		for (ll i = 0; i < n; i++) inv[i] = inverse(p[i], MOD);
		bit = new Bit<MOD>(h);
	}
	ll operator()(int l, int r) { // retorna hash s[l...r]
		return bit->query(l, r) * inv[l] % MOD;
	}
	void update(ll i, ll ch) {
	    bit->update(i, -(p[i]*s[i]%MOD));
	    bit->update(i, p[i]*ch % MOD);
	    s[i] = ch;
	}
};
template<int MOD> int str_hash<MOD>::P = 73; // l > |sigma|

void solve(ll tt, ll ti) {
    cin >> n >> m;
    string s; cin >> s;
    string t = s;
    reverse(all(t));
    str_hash<1000000007> h1(s);
    str_hash<1000000007> h2(t);
    for (ll i = 0; i < m; i++) {
        ll type; cin >> type;
        if (type == 1) {
            ll k; cin >> k;
            char ch; cin >> ch;
            k--;
            h1.update(k, ch);
            h2.update(n-k-1, ch);
        } else {
            ll a, b; cin >> a >> b;
            a--, b--;
            ll q1 = h1(a, b);
            ll q2 = h2(n-b-1, n-a-1);
            cout << (q1 == q2 ? "YES" : "NO") << nl;
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
