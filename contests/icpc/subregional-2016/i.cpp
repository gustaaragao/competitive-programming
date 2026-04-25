#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define int long long
#define endl '\n' //<< flush
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cerr << #x << " = " << x << endl
#define uniq(v) sort(all(v)); v.erase(unique(all(v)), v.end())
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int, int, int> ti;
const int MOD = 1e9 + 7; // 998244353;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 5e4 + 10;

int n, a[MAXN], esq[MAXN], dir[MAXN];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    esq[0] = 1;
    for (int i = 1; i < n; i++) {
        esq[i] = min(esq[i-1] + 1, a[i]);
    }
    dir[n-1] = 1;
    for (int i = n-2; i >= 0; i--) {
        dir[i] = min(dir[i+1] + 1, a[i]);
    }
    int ans = 0; 
    for (int i = 0; i < n; i++) {
        ans = max(ans, min(esq[i], dir[i]));
    }    
    cout << ans << endl;
    return 0;
}