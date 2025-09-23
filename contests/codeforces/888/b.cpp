#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define all(x) (x).begin(),(x).end()

#define MAXN 200005

typedef pair<int, int> pi;

void solve() {
    int n; cin >> n;
    vector<int> pares, impares;
    vector<int> pos_pares, pos_impares;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x % 2 == 0) {
            pares.pb(x);
            pos_pares.pb(i);
        } else {
            impares.pb(x);
            pos_impares.pb(i);
        }
        
    }
    sort(all(pares));
    sort(all(impares));
    sort(all(pos_pares));
    sort(all(pos_impares));
    vector<int> ans(n);
    for (int i = 0; i < pares.size(); i++) {
        ans[pos_pares[i]] = pares[i];
    }
    for (int i = 0; i < impares.size(); i++) {
        ans[pos_impares[i]] = impares[i];
    }
    if (is_sorted(all(ans))) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int tc; cin >> tc;
    while (tc--) solve();
}