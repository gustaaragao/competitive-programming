#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back

typedef long long ll;
typedef pair<int, int> pi;

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n, x; cin >> n >> x;
    
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        ll a; cin >> a;
        if (x % a == 0) ans.pb(i+1);
    }

    cout << (int) ans.size() << endl;
    for (auto x : ans) cout << x << " ";
    cout << endl;
}