#include <bits/stdc++.h>
using namespace std; 

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
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define MAXN 100005
ll n, k, a, b;

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    vector<ll> v(n); for (auto &x : v) cin >> x;
    sort(all(v));
    cin >> k;
    while (k--) {
        cin >> a >> b;
        int x = lower_bound(all(v), a) - v.begin(); // x >= a
        int y = upper_bound(all(v), b) - v.begin(); // x > b
        x = n - x; y = n - y;
        // dbg(x); dbg(y); cout << "----" << endl;
        cout << abs(x - y) << endl;
    }
}