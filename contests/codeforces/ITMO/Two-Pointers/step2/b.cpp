#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {
    int n, s; cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    // minimizar o segmento [i, j] com soma >= s
    int i = 0, sum = 0, ans = LLONG_MAX;
    for (int j = 0; j < n; j++) {
        sum += a[j];
        if (sum < s) continue;
        while (sum - a[i] >= s) {
            sum -= a[i];
            i++;
        }
        ans = min(ans, j - i + 1);
    }
    cout << (ans == LLONG_MAX ? -1 : ans) << endl;
}