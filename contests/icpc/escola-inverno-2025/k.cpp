#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;

#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second

const int MAXN = 2e5 + 10;
ll n, k, a[MAXN], prefix[MAXN+1];

ll count(ll m) {
    prefix[0] = 0;
    for (int i = 1; i <= n; i++) {
        // Contar elementos <= m (mediana <= m)
        prefix[i] = prefix[i-1] + (a[i-1] <= m ? 1 : -1);
    }
    ll ans = 0;
    ord_set<pair<ll,int>> s; 
    s.insert({0, -1}); // prefixo vazio
    for (int i = 1; i <= n; i++) {
        // Quantas somas são positivas? S[i] - S[j] >= 0 => S[i] >= S[j]
        ans += s.order_of_key({prefix[i] + 1, -1});
        s.insert({prefix[i], i});
    }
    return ans;
}

bool check(ll m) {
    if (count(m) >= k) return true;
    else return false;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    ll l = 1, r = 1e9 + 5;
    while (l < r) {
        ll m = l + (r - l) / 2;
        if (check(m)) r = m;
        else l = m + 1;
    }
    cout << l << endl;
}
