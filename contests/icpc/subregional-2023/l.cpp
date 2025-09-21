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

signed main(){
    FAST_IO
    
    string s; cin >> s;
    int k; cin >> k;

    vector<vector<char>> grupos(k);
    for (int i = 0; i < s.size(); i++) {
        grupos[i % k].pb(s[i]);
    }

    for (int i = 0; i < k; i++) {
        sort(rall(grupos[i]));
    }

    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        ans.pb(grupos[i % k].back());
        grupos[i % k].pop_back();
    }
    cout << ans << endl;
}