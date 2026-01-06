#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define sz(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << x << endl

void solve() {
    int n, k; cin >> n >> k;

    auto pref = [&](int i) {
        int len = i;
        int first = k;
        int last = k + i - 1;
        return (first + last) * len / 2;
    };

    int total = n * (2*k + n - 1) / 2; // sufixo = total - prefixo
    /*
    soma = prefixo - sufixo = prefixo - (total - prefixo)
    soma(i) = 2*prefixo(i) - total

    - prefixo(i) cresce com i
    - soma(i) cresce com i

    são funções monótomas
    */
    int l = 1, r = n, ans = LLONG_MAX;
    while (l <= r) {
        int m = (l+r)/2;
        int sum = 2*pref(m)-total; // 2*pref(m) ~ total --> sum ~ 0
        ans = min(ans, llabs(sum));
        if (sum < 0) { // queremos que a sum se aproxime de 0
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    // l -> primeiro índice tal que sum > 0
    // r -> último índice tal que sum <= 0
    assert(ans == min(abs(2*pref(l)-total), abs(2*pref(r)-total)));
    cout << ans << endl;
}


signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc; while(tc--) solve();
}