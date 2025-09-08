#include <bits/stdc++.h>
using namespace std; 

#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(0);
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

signed main(){
    FAST_IO
    int t; cin >> t;
    while (t--) {
        ll a, b; cin >> a >> b;
        // Impossível
        if (a % 2 == 0 && b % 2 != 0) {
            cout << -1 << endl;
            continue;
        } else if (a % 2 != 0 && b % 4 == 2) {
            cout << -1 << endl;
            continue;
        }

        // Possível
        if (a % 2 != 0 && b % 2 != 0) {
            cout << a * b + 1 << endl;
        } else if (a % 2 == 0 && b % 2 == 0) {
            ll sum1 = a + b;
            ll sum2 = (a * b) / 2 + 2;
            cout << max(sum1, sum2) << endl;
        } else { 
            ll sum1 = 2 * a + b / 2;
            ll sum2 = (a * b) / 2 + 2;
            cout << max(sum1, sum2) << endl;
        }
    }
}