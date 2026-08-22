#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define nl '\n'
using namespace std;

const ll M = 1e9 + 7;
const ll MAXN = 1e6 + 4;
const ll INF = 1e9;

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

int main() {
	// your code goes here
	ios_base::sync_with_stdio(0), cin.tie(0);
    string s; cin >> s;
    ll n = s.size();

    vector<int> z = z_function(s);
    for (ll i = 1; i <= n; i++) {
        ll ok = 1;
        for (ll j = i; j < n; j += i) {
            if (n - j >= i) {
                ok &= z[j] >= i;
            } else {
                ok &= z[j] == n-j;
            }
        }
        if (ok) cout << i << " ";
    }
    cout << nl;

    return 0;
}
