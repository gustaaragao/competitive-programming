#include <bits/stdc++.h>
using namespace std; 

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
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define MAXN 100000
int n, k, v[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> v[i];
    while (k--) {
        int x; cin >> x;
        int l = 0, r = n-1;
        while (l < r) {
            int m = (l+r)/2;
            if (x > v[m]) l = m + 1;
            else r = m;
        }
        if (v[l] == x) 
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}