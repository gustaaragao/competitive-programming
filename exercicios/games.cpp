#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define sz(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pi;

const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e2 + 10;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    vector<pi> v[n];
    multiset<int> ms; 
    for (int i = 0; i < n; i++) {
        cin >> v[i].ff >> v[i].ss;
        ms.insert(v[i].ss);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
         auto [h, a] = v[i];
         ans += ms.count(h);
    }
    cout << ans << endl;
}
