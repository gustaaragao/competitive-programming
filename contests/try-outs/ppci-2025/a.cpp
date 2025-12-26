#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    unordered_map<string, int> mp;
    vector<string> names = {
        "Abigail", "Sebastian", "Penny", "Sam", "Leah", 
        "Harvey", "Haley", "Maru", "Alex", "Emily"
    };
    for (auto n : names) mp[n] = 0;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int v; cin >> v;
        mp[s] += v;
    }
    for (auto name : names) {
        if (mp[name] / 250 >= 1) {
            cout << name << " " << min(mp[name] / 250, 8LL) << endl;
        }
    }
}