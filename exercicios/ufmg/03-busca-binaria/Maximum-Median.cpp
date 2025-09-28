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

const int MAXN = 2e5 + 10;

ll n, k, v[MAXN];

bool possible(ll m) {
    ll moves = 0;
    for (int i = n / 2; i < n; i++) {
        if (v[i] < m) moves += (m - v[i]); // igualar v[i] com m
        if (moves > k) return false;
    }
    if (moves <= k) return true;
    return false;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v, v+n);
    ll l = 0, r = 2e9+5;
    while (l < r) {
        ll m = l + (r-l+1)/2;
        if (possible(m)) l = m;
        else r = m - 1;
    }
    cout << l << endl;
}