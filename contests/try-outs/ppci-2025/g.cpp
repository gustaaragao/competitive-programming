#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, k, a; cin >> n >> k >> a;
    vector<int> price(n); for(auto &x : price) cin >> x;
    sort(price.rbegin(), price.rend());
    int x = 0, cnt = 0;
    while (cnt < k) {
        if (price.back() > a) {
            break;
        }
        a -= price.back(); 
        x += price.back();
        price.pop_back();
        cnt++;
    }
    if (cnt == k) {
        cout << x << endl;
    } else {
        cout << "Nao e possivel" << endl;
    }
}