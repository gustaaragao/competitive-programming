#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second

void solve() {
    string r; cin >> r;
    int n = (int) r.size();

    int ans = LLONG_MAX;

    // Estratégia 1: Mudar todos os u para s
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (r[i] == 'u') {
            cnt++;
        }
    }
    ans = min(cnt, ans);
    
    cnt = 0;
    if (r[0] == 'u') {
        r[0] = 's';
        cnt++;
    }
    if (r[n-1] == 'u') {
        r[n-1] = 's';
        cnt++;
    } 

    for (int i = 1; i < n-1; i++) {
        if (r[i] == 'u') {
            if (r[i-1] != 's') {
                r[i-1] = 's';
                cnt++;
            } else if (r[i+1] != 's') {
                r[i+1] = 's';
                cnt++;
            }
        } 
    }
    ans = min(cnt, ans);
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc; while (tc--) solve(); 
}