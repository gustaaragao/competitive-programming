#include <bits/stdc++.h>
using namespace std; 

#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(0);
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

void solve(){
    string s; cin >> s;
    bool find = false;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i-1]) {
            find = true;
            break;
        }
    }
    cout << (find ? 1 : s.size()) << endl;
}

signed main(){
    FAST_IO
    int tc; cin >> tc;
    while (tc--) solve();
}