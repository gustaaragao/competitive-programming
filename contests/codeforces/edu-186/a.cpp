#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << x << endl

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    bool has2025 = false, has2026 = false;
    for (int i = 0; i + 3 < n; i++) {
        string sub = s.substr(i, 4);
        if (sub == "2025") has2025 = true;
        if (sub == "2026") has2026 = true;
    }

    if (!has2025 or has2026) {
        cout << 0 << endl;
    } else {
        // Não tem 2026 e tem 2025 -> Logo, basta mudar 2025 para 2026 com uma troca
        cout << 1 << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc; while(tc--) solve();
}