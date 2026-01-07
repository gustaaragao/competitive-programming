#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define dbg(x) cout << #x << " = " << x << endl

signed main() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    
    int i = 0, j = 0, ans = 0;
    while (i < n and j < m) {
        if (a[i] < b[j]) {
            i++;
        } else if (a[i] > b[j]) {
            j++;
        } else {
            int x = a[i];
            int cntA = 0, cntB = 0;
            while (i < n and a[i] == x) {
                cntA++;
                i++;
            }
            while (j < m and b[j] == x) {
                cntB++;
                j++;
            }
            ans += cntA * cntB;
        }
    }
    cout << ans << endl;
}