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

const double EPS = 1e-6; // Precisão

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    double n; cin >> n;
    double l = 0, r = 1e8+10;
    // while (r - l > EPS) {
    for (int i = 0; i < 200; i++) {
        double m = (l+r)/2;

        if (m*m > n) r = m;
        else l = m;
    }
    cout << (l+r)/2 << endl;
}