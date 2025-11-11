#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define ff first
#define ss second

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s; cin >> s;
    int n = (int) s.size();
    unordered_map<string, int> mp;
    // "boooo"
    mp["boooo"] = -1;
    mp["booo"] = 0, mp["boo"] = 0, mp["bo"] = 0, mp["b"] = 0;
    // "ha"
    mp["ha"] = 1;
    mp["h"] = 0;
    // "bravo"
    mp["bravo"] = 3;
    mp["brav"] = 0, mp["bra"] = 0, mp["br"] = 0;
    
    string temp; temp.reserve(n);
    int ans = 0LL;
    for (int i = 0; i < n; i++) {
        temp += s[i];
        if (mp.contains(temp)) {
            ans += mp[temp];
        } else {
            temp.clear();
            temp += s[i];
        }
    }
    cout << ans << endl;
}
