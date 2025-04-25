#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define ff first
#define ss second
#define pb push_back

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        map<char, int> mp;
        while (n--) {
            char c; cin >> c;
            mp[c]++;
        }
        ll ans = ((mp['1'] - 1) * mp['1']) + ((mp['1'] + 1) * mp['0']);
        cout << ans << endl; 
    }    

    return 0;
}