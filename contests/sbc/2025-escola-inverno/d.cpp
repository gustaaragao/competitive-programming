#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int, int, int> ti;

const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

    int n; cin >> n;
    vector<int> a(n);
    map<int, ll> mp; // map<int, ll> na linha 45 tem uma multiplicacao que pode causar overflow
    for (int i = 0; i < n; i++) {
        int aux; cin >> aux;
        mp[aux]++;
        a[i] = aux;
    }

    sort(all(a));
    vector<ti> prefix;
    for (int i = 1; i < n; i++) {
        int ai = a[i - 1], aj = a[i];
        if (ai != aj) {
            int diff = aj - ai;
            ti t = {i - 1, i, diff};
            prefix.pb(t);
        }
    }

    ll ans = 0;
    for (auto [i, j, diff] : prefix) {
        if (diff == 1) {
            ans += mp[a[i]] * mp[a[j]];
        }
    }

    cout << ans << endl;

    return 0;
}
