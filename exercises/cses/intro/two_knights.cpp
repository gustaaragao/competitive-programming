#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define all(x) (x).begin(), (x).end()

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    ll n; cin >> n;
    for (ll k = 1; k <= n; k++) {
        // (k² * (k² - 1)) / 2
        ll total = ((k * k) * ((k * k) - 1)) / 2;
        ll attacking_ways = 4 * (k - 1) * (k - 2); // 3x2 or 2x3
        ll ans = total - attacking_ways;
        cout << ans << endl;
    }
    return 0;
}