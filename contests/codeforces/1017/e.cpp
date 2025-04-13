#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _

    int t; cin >> t;
    
    while (t--) {
        int n; cin >> n;
        vector<ll> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        ll ans = 0;

        for (int k = 0; k < n; k++) {
            ll sum = 0;
            for (int i = 0; i < n; i++) sum += (v[k] ^ v[i]);
            ans = max(ans, sum);
        }

        cout << ans << endl;
    }
    
    return 0;
}