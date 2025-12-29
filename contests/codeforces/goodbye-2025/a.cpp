#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second

void solve() {
    string s; cin >> s;
    int n = (int) s.size();

    string s1; s1.reserve(n);
    char prev = '?';
    for (int i = 0; i < n; i++) {
        if (s[i] == 'N' and prev == 'N') {
            continue;
        } else {
            s1.push_back(s[i]);
        }
        prev = s[i];
    }

    n = (int) s1.size();

    string s2; s2.reserve(n);
    for (int i = 0; i < n; i++) {
        if ((s1[i] == 'N' and s1[i+1] == 'Y') or (s1[i] == 'Y' and s1[i+1] == 'N')) {
            s2.push_back('Y');
            i++;
        } else {
            s2.push_back(s1[i]);
        }
    }
    if (s2 == "Y" or s2 == "N" or s2 == "YN" or s2 == "NY") {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc; while (tc--) solve();
}