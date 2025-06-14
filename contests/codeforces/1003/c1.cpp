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

void solve(vector<int> a, int b) {
    a[0] = min(a[0], b - a[0]);
    for (int i = 1; i < a.size(); i++) {
        int min_a = min(a[i], b - a[i]);
        if (min_a >= a[i - 1]) continue;
        else {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(){ _

    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<int> a(n); for (auto &x : a) cin >> x;
        int b; cin >> b;
        solve(a, b);
    }

    return 0;
}