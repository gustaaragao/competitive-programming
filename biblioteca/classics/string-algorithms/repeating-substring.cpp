#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define pll pair<ll, ll>
#define vl vector<ll>
#define vll vector<pll>
#define vvl vector<vl>
#define nl '\n'

using namespace std;

const ll M = 1e9 + 7;

ll n, m;

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
		if (ra[i] == n-1) { k = 0; continue; }
		int j = sa[ra[i]+1];
		while (i+k < n and j+k < n and s[i+k] == s[j+k]) k++;
		lcp[ra[i]] = k;
	}
	return lcp;
}

void solve() {
    string s; cin >> s;
    n = s.size();
    vector<int> sa = suffix_array(s);
    vector<int> lcp = kasai(s, sa);
    ll ans = n-sa[0];
    ll mx = 0;
    ll start = -1;
    for (ll i = 0; i < n-1; i++) {
        if (lcp[i] > mx) {
            mx = lcp[i];
            start = sa[i];
        }
    }
    if (start == -1) {
        cout << -1 << nl;
    } else {
        cout << s.substr(start, mx) << nl;
    }
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(0), cin.tie(0);
	solve();
    return 0;
}
