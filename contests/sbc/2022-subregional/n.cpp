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

// Faz a soma de a[L...R], sendo que a está 1-indexed
int qry(int l, int r, const vector<int> &sum) {
    return sum[r] - sum[l-1];
}

signed main(){
    FAST_IO

    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto &x: a) cin >> x;
    for (auto &x: b) cin >> x;
    int k, l; cin >> k >> l;
    // Calcular a soma acumulada para a e b
    vector<int> sum_a(n+1), sum_b(n+1); // 1-indexed
    sum_a[1] = a[0]; sum_b[1] = b[0];
    for (int i = 2; i <= n; ++i) {
        sum_a[i] = sum_a[i-1] + a[i-1];
        sum_b[i] = sum_b[i-1] + b[i-1];
    }
    ll ans = 0;
    // Brutar todas as possibilidades para K
    
    cout << ans << endl;
}   