#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back

typedef long long ll;
typedef pair<int, int> pi;

bool bonitas[30][30];

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s; cin >> s;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        char u, v; cin >> u >> v;
        bonitas[u-'a'][v-'a'] = true;
    }
    
    bool ok = true;
    for (int i = 1; i < (int) s.size(); i++) {
        char u = s[i-1], v = s[i];
        if (!bonitas[u-'a'][v-'a']) {
            ok = false;
            break;
        }
    }

    if (ok) cout << "SIM";
    else cout << "NAO";
    cout << endl;
}