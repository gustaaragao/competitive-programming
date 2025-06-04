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

const ll P = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

    int t; cin >> t;
    while(t--) {
        int n, q; cin >> n >> q;
        vector<ll> a(n); for (auto &x : a) cin >> x;
        vector<ll> k(q); for (auto &x : k) cin >> x;
        for (auto length : k) {
            ll ans = 0;
            for (auto diff : a) {
                if (length >= diff) ans += diff;
                else break;
            }
            cout << ans << " ";
            ans = 0;
        }
        cout << endl;
    }    

    return 0;
}