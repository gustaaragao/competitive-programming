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

int n, q;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> q;
    vector<string> input(n); 
    map<string, int> mp, cnt;
    map<string, bool> imune, bug;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int l; cin >> l;
        mp[s] = l;
        cnt[s] = 0;
        input[i] = s;
    }
    for (int i = 0; i < q; i++) {
        string t; cin >> t;
        int x; cin >> x;
        if (mp.contains(t)) {
            if (x <= mp[t]) {
                if (!imune[t]) {
                    bug[t] = true;
                }
            } else {
                cnt[t]++; // conta 1 erro
                if (cnt[t] >= 3) imune[t] = true;
            }
        }
    }
    vector<string> ans;
    for (auto x : input) {
        if (bug[x]) {
            ans.pb(x);
        }
    }
    cout << sz(ans) << endl;
    for (auto x : ans) cout << x << endl;
}