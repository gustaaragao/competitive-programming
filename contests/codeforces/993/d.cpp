#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    unordered_map<int, int> mp_a, mp_b;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp_a[a[i]]++;
    }

    queue<int> diff;
    for (int i = 1; i <= n; i++) {
        if (!mp_a.count(i)) {
            diff.push(i);
        }
    }

    int max_occur = 0;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        if (!mp_b.count(a[i])) {
            b[i] = a[i];
            mp_b[b[i]]++;
            max_occur = max(max_occur, mp_b[b[i]]);
        } else if (max_occur < mp_b[a[i]]) {
            b[i] = a[i];
            mp_b[b[i]]++;
            max_occur = max(max_occur, mp_b[b[i]]);
        } else if (max_occur == mp_b[a[i]]) {
            b[i] = diff.front(); diff.pop();
            mp_b[b[i]]++;
            max_occur = max(max_occur, mp_b[b[i]]);
        } else { // max_occur > mp_b[a[i]]
            continue;
        }
    }

    for (auto x : b) cout << x << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc;
    while (tc--) solve();
}