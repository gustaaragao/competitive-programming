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

vector<int> pi(string s) {
    vector<int> p(s.size());
    for (int i = 1, j = 0; i < (int) s.size(); i++) {
        while (j > 0 and s[i] != s[j]) j = p[j-1];
        if (s[i] == s[j]) j++;
        p[i] = j;
    }
    return p;
}

int matching(string &t, string& s) {
    vector<int> p = pi(s+'$');
    int matchs = 0;
    for (int i = 0, j = 0; i < (int) t.size(); i++) {
        while (j > 0 and t[i] != s[j]) j = p[j-1];
        if (t[i] == s[j]) j++;
        if (j == (int) s.size()) matchs++;
    }
    return matchs;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    string t, s; cin >> t >> s;
    int ans = matching(t, s);
    cout << ans << endl;
}