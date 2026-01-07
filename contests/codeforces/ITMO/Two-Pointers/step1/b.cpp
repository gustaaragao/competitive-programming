#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

signed main() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> ans(m);
    int i = 0;
    for (int j = 0; j < m; j++) {
        while (i < n and a[i] < b[j]) i++;
        ans[j] = i;
    }
    for (auto x : ans) cout << x << " ";
    cout << endl;
}