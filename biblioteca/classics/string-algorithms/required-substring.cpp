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

ll len[101][26];

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    memset(len, 0, sizeof(len));
    len[0][s[0]-'A'] = 1;
    for (int i = 1; i < n; i++) {
        char old = s[i];
        for (ll k = 0; k < 26; k++) {
            s[i] = old;
            if (k == (s[i] - 'A')) {
                len[i][k] = i+1;
                continue;
            }
            s[i] = (char) (k + 'A');
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])
                j++;
            len[i][k] = j;
        }
        s[i] = old;
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void solve() {
    cin >> n;
    string s; cin >> s;
    m = s.size();

    auto p = prefix_function(s);

    ll dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 0; j < 26; j++) {
            for (ll k = 0; k < m; k++) {
                dp[i][len[k][j]] += dp[i-1][k];
                dp[i][len[k][j]] %= M;
            }
        }
    }

    ll ans = 1;
    for (ll i = 0; i < n; i++) {
        ans = ans * 26 % M;
    }

    for (ll k = 0; k < m; k++) {
        ans = (ans - dp[n][k] + M) % M;
    }

    cout << ans << nl;
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(0), cin.tie(0);
	solve();
    return 0;
}
