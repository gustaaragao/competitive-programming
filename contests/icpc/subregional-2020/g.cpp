#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
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


signed main(){ _

    int c; cin >> c;
    int atual = 100, ans = 100;
    while (c--) {
        int v; cin >> v;
        atual += v;
        ans = max(ans, atual);
    }

    cout << ans << endl;
}