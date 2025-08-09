#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pi;

const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

    ll n, m, k; cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    sort(all(a));
    sort(all(b));

    ll ans = 0;
    int ptrA = 0, ptrB = 0;
    
    while (ptrA < n && ptrB < m) {
        if (abs(a[ptrA] - b[ptrB]) <= k) {
            ans++;
            ptrA++;
            ptrB++;
        } else if (a[ptrA] > b[ptrB]) {
            ptrB++;
        } else {
            ptrA++;
        }
    }

    cout << ans << endl;
    
    return 0;
}