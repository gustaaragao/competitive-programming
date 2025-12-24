#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define sz(x) (int) (x).size()

void solve() {
    int n; cin >> n;
    vector<int> pares, impares;
    pares.reserve(n); impares.reserve(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x % 2 == 0) {
            pares.push_back(x);
        } else {
            impares.push_back(x);
        }
    }
    if (sz(pares) == 0) {
        for (auto x : impares) cout << x << " ";
        cout << endl;
        return;
    } else if (sz(impares) == 0) {
        for (auto x : pares) cout << x << " ";
        cout << endl;
        return;
    }

    sort(pares.rbegin(), pares.rend());
    sort(impares.rbegin(), impares.rend());
    vector<int> ans; ans.reserve(n);
    while (!pares.empty() and !impares.empty()) {
        if (pares.back() < impares.back()) {
            ans.push_back(pares.back());
            pares.pop_back();
        } else {
            ans.push_back(impares.back());
            impares.pop_back();
        }
    }
    while (!pares.empty()) {
        ans.push_back(pares.back());
        pares.pop_back();
    }
    while (!impares.empty()) {
        ans.push_back(impares.back());
        impares.pop_back();
    }
    for (auto x : ans) cout << x << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc; while (tc--) solve();
}
