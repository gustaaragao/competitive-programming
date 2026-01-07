#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
#define int ll
#define ff first
#define ss second
#define endl '\n'
#define pb push_back
#define sz(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << x << endl
#define uniq(v) sort(all(v)); v.erase(unique(all(v)), v.end())
const int MOD = 1e9 + 7; // 998244353;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    vector<int> freq(n + 5, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
    
    int total_mex = 0;
    while (freq[total_mex] > 0) {
        total_mex++;
    }
    
    cout << min(k - 1, total_mex) << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc; cin >> tc; while(tc--) solve();
}