#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

const ll M = 1e9 + 7;
const ll MAXN = 1e6 + 4;
ll is_end[MAXN];

vector<vector<ll>> trie(1e6+5, vector<ll>(26));
ll id = 0;

vector<int> z_function(string &s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void insert(string &s) {
    ll node = 0;
    for (auto ch : s) {
        if (!trie[node][ch-'a']) trie[node][ch-'a'] = ++id;
        node = trie[node][ch-'a'];
    }
    is_end[node] = 1;
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(0), cin.tie(0);
    string s; cin >> s;
    int k; cin >> k;
    int n = s.size();
    memset(is_end, 0, sizeof(is_end));

    for (int i = 0; i < k; i++) {
        string t; cin >> t;
        insert(t);
    }

    vector<int> dp(n+1);
    dp[n] = 1;
    for (int i = n-1; i >= 0; i--) {
        ll node = 0;
        for (ll j = i; j < n; j++) {
            if (!trie[node][s[j]-'a']) break;
            node = trie[node][s[j]-'a'];
            if (is_end[node]) {
                dp[i] += dp[j+1];
                dp[i] %= M;
            }
        }
    }

    cout << dp[0] << endl;

    return 0;
}
