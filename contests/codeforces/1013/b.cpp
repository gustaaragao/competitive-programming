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
    while (t--) {
        int n, x; cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(all(a), greater<int>());

        int ans = 0;
        int team_size = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] * team_size >= x) {
                // the team is strong
                ans++;
                team_size = 0;
            }
            team_size++;
        }
        cout << ans << endl;
    }

    return 0;
}