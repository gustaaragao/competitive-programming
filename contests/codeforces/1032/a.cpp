#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> ii;

const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

    int t; cin >> t;
    while(t--) {
        int n, s; cin >> n >> s;
        int v[n]; for (auto &x : v) cin >> x;
        
        int dist1, dist2;
        dist1 = abs(s - v[0]) + abs(v[n - 1] - v[0]);
        dist2 = abs(v[n - 1] - s) + abs(v[n - 1] - v[0]);
        cout << min(dist1, dist2) << endl;

    }

    return 0;
}