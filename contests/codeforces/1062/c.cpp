#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define sz(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;
typedef pair<int, int> pi;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ll MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    deque<pi> min_even, min_odd;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] % 2 == 0) {
            min_even.eb(arr[i], i);
        } else {
            min_odd.eb(arr[i], i);
        }
    }
    sort(all(min_even));
    sort(all(min_odd));

    vector<int> ans(n);
    while (!min_even.empty() and !min_odd.empty()) {
        // .front() -> menor valor
        // .back() -> maior valorx
        if (min_even.front() < odd) {
            min_even.pop_front();

        }
    }

    if (!min_even.empty()) {
        int x = min_even.front(); min_even.pop_back();
    }

    if (!min_odd.empty()) {
        int x = min_odd.front(); min_odd.pop_back();
    }
    
    for (auto x : ans) cout << x << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t0; cin >> t0;
    while(t0--) solve();
}
