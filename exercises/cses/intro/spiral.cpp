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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

    int t; cin >> t;
    while (t--) {
        ll y, x; cin >> y >> x;
        
        ll area, ans;
        if (y > x) {
            area = (y - 1) * (y - 1);
            if (y % 2 == 0) ans = area + (2 * y - x);
            else ans = area + x;
        } else {
            area = (x - 1) * (x - 1);
            if (x % 2 == 0) ans = area + y;
            else ans = area + (2 * x - y);
        }

        cout << ans << endl;
    }    

    return 0;
}