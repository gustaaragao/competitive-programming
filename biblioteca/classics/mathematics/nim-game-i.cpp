#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int MAXN = 2e5 + 10;

int v[MAXN];

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        // caso o xor de todos os x[i] == 0 -> Adversario ganha. Caso contrário, Breno ganha.
        int xr = 0;
        for (int i = 0; i < n; i++) {
            xr ^= v[i];
        }
        if (xr != 0) {
            cout << "first" << endl;
        } else {
            cout << "second" << endl;
        }
    }
}
