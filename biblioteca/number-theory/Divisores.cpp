#include <bits/stdc++.h>
using namespace std;

#define pb push_back

signed main() {
    int n; cin >> n;
    // O(nlog(n))
    vector<int> divisores[n+1];
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) { // j -> múltiplo de i
            divisores[j].pb(i);
        }
    }
    // Debug
    cout << "divisores: ";
    for (int i = 0; i <= n; i++) {
        cout << i << ": ";
        for (auto x : divisores[i]) cout << x << " ";
        cout << '\n';
    }
    cout << '\n';
}