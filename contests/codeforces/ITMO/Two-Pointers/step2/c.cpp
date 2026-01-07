#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {
    int n, s; cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int i = 0, sum = 0, ans = 0;
    for (int j = 0; j < n; j++) {
        sum += a[j];
        while (sum > s) {
            sum -= a[i];
            i++;
        }
        if (sum <= s) {
            ans += (j - i + 1);
        }
    }
    cout << ans << endl;
}