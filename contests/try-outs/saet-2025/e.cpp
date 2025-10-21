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

#define int long long

const int MAX = 1e5 + 10;

int n, m, l;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    vector<int> v;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        v.pb(x);
    }
    cin >> l;
    sort(all(v));
    auto it = upper_bound(all(v), l);
    if (it == v.end()) {
        cout << "NAO" << endl;
        return 0;
    }
    int qtd = v.end() - it;
    if (qtd >= n) {
        cout << "SIM" << endl;
    } else {
        cout << "NAO" << endl;
    }
}