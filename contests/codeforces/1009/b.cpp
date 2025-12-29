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
    multiset<int> a;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.insert(x);
    }
    
    while ((int) a.size() > 1) {
        int x1 = *a.begin();
        a.erase(a.begin());
        
        int x2 = *a.begin();
        a.erase(a.begin());
        
        a.insert(x1 + x2 - 1);
    }

    cout << *a.begin() << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc; while(tc--) solve();
}