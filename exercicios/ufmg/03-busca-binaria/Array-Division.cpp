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

const int MAXN = 2e5 + 5;

int n, k, v[MAXN];

bool possible(ll m) {
    ll subarray_count = 0, curr_sum = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > m) return  false;
        if (curr_sum + v[i] > m) {
            subarray_count++;
            curr_sum = 0;
        }
        curr_sum += v[i];
    }
    if (curr_sum != 0) subarray_count++;
    return subarray_count <= k;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v, v+n);
    ll l = *max_element(v, v+n);
    ll r = accumulate(v, v+n, 0LL);
    while (l < r) {
        ll m = l + (r - l) / 2;
        if (possible(m)) r = m;
        else l = m + 1;
    }
    cout << l << endl;
}