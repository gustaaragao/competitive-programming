#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second

void solve() {
    int n; cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> pref(n, 0);
    pref[0] = a[0];
    for (int i = 1; i < n; i++) {
        // para todo i de [1, n-1] eu posso otimizar ele (mudando o sinal para +),
        // pois posso postergar a remoção do índice 0
        pref[i] = pref[i-1] + llabs(a[i]);
    }
    
    vector<int> suf(n, 0);
    suf[n-1] = a[n-1];
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = suf[i + 1] + a[i];
    }
   
    int ans = LLONG_MIN;
    // Borda k = 0 -> -suf[k+1]
    ans = max(ans, -suf[1]);
 
    // Borda k = n-1 -> pref[k-1]
    ans = max(ans, pref[n-2]);
 
    for (int k = 1; k < n-1; k++) {
        ans = max(ans, pref[k-1] - suf[k+1]);
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc; while (tc--) solve();
}