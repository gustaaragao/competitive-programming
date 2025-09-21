#include <bits/stdc++.h>
using namespace std; 

#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pi;

const ll MOD = 1e9 + 7;

signed main(){
    FAST_IO

    ll d, c, r; cin >> d >> c >> r;
    queue<ll> atv_c;
    for (int i = 0; i < c; i++) {
        ll x; cin >> x;
        atv_c.push(x);
    }
    queue<ll> atv_r;
    for (int i = 0; i < r; i++) {
        ll x; cin >> x;
        atv_r.push(x);
    }
    ll ans = 0;
    while (!atv_c.empty()) {
        if (atv_c.front() <= d) {
            d -= atv_c.front();
            atv_c.pop();
            ans ++;
        } else {
            if (atv_r.empty()) break;
            d += atv_r.front();
            atv_r.pop();
            ans ++;
        }
    }
    while (!atv_r.empty()) {
        d += atv_r.front();
        atv_r.pop();
        ans ++;
    }
    cout << ans << endl;
}