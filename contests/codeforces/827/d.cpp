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

vector<int> coprimes[1001];

int main(){ _
    for (int i = 1; i < 1001; i++) {
        for (int j = 1; j < 1001; j++) {
            if (gcd(i, j) == 1) {
                coprimes[i].push_back(j);
            }
        }    
    }
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(1001, -1);
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            a[x] = max(a[x], i+1);
        }
        int ans = -1;
        for (int i = 1; i <= 1000; i++) {
            for (int j : coprimes[i]) {
                if (a[i] != -1 && a[j] != -1) {
                    ans = max(ans, a[i] + a[j]);
                }
            }
        }
        cout << ans << endl;
    }   

    return 0;
}