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

const int MAXN = 1e5 + 10;
const long double EPS = 1e-7;

ll n, k, a[MAXN];

bool is_possible(long double m) {
    long long total = 0;
    for (int i = 0; i < n; i++) {
        total += (a[i] / m);
    }
    return total >= k;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    long double l = 0, r = 1e7;
    while ((r - l) > EPS) {
        long double m = (l+r)/2;
        if (is_possible(m)) l = m;
        else r = m;
    }
    cout <<  fixed << setprecision(6) << l << endl;
}