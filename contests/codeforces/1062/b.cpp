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
    string s, t; cin >> s >> t;
    map<char, int> mp_s, mp_t;
    for (int i = 0; i < n; i++) {
        mp_s[s[i]]++;
        mp_t[t[i]]++;
    }
    bool ok = true;
    for (auto [c, cnt] : mp_s) {
        if (cnt != mp_t[c]) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t0; cin >> t0;
    while (t0--) solve();
}
