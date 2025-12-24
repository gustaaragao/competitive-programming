#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void solve() {
    string a; cin >> a;
    int n = (int) a.size();
    string b;
    for (int i = n-1; i >= 0; i--) {
        if (a[i] == 'q') {
            b.push_back('p');
        } else if (a[i] == 'p') {
            b.push_back('q');
        } else {
            b.push_back('w');
        }
    }
    cout << b << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc;
    while (tc--) solve();
}