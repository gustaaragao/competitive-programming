#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define sz(x) (int) (x).size()

void solve() {
    int n, k, x; cin >> n >> k >> x;
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    n = sz(arr);

    vector<pair<int, int>> pt(n);
    auto check = [&](int m) {
        for (int i = 0; i < n; i++) {
            pt[i] = {arr[i] - (m-1), arr[i] + (m-1)};
        }
        int sum = 0;
        for (int i = 1; i < n; i++) {
            if (pt[i-1].second < pt[i].first) {
                int dx = pt[i].first - pt[i-1].second - 1;
                sum += dx;
            }
        }
        // Limite da Esquerda
        if (pt[0].first > 0) {
            sum += pt[0].first;
        }

        // Limite da Direita
        if (x > pt[n-1].second) {
            sum += x - pt[n-1].second;
        }

        return sum >= k;
    };

    int l = 0, r = x+1;
    while (l < r) {
        int m = l + (r - l + 1) / 2;
        if (check(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }

    if (l == 0) {
        for (int i = 0; i < k; i++) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    
    for (int i = 0; i < n; i++) {
        pt[i] = {arr[i] - (l-1), arr[i] + (l-1)};
    }

    vector<int> ans;
    // Limite da Esquerda
    if (pt[0].first > 0) {
        for (int i = 0; i < pt[0].first and sz(ans) < k; i++) {
            ans.push_back(i);
        }
    }
    
    // Limite da Direita
    if (x > pt[n-1].second) {
        for (int i = pt[n-1].second + 1; i <= x and sz(ans) < k; i++) {
            ans.push_back(i);
        }
    }

    for (int i = 1; i < n and sz(ans) < k; i++) {
        for (int u = pt[i-1].second + 1; u < pt[i].first and sz(ans) < k; u++) {
            ans.push_back(u);
        }
    }
    
    sort(ans.begin(), ans.end());
    for (auto u : ans) {
        cout << u << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc; while (tc--) solve();
}
