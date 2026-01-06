#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define sz(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << x << endl

const int MAXN = 2e5 + 10;

void solve() {
    int n; cin >> n;
    unordered_map<int, bool> has0, has1;
    unordered_set<int> xx;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        xx.insert(x);
        if (y == 1) has1[x] = true;
        else has0[x] = true;
    }
    int ans = 0;
    // Maneira 1: (x, 0) e (x, 1) -> dá para formar n-2 triângulos
    for (auto x : xx) {
        if (has0.count(x) and has1.count(x)) ans += n-2;
    }

    // Maneira 2: 
    // - Para todo (x+1, 1), preciso ter (x, 0) e (x+2, 0)
    // - Para todo (x+1, 0), preciso ter (x, 1) e (x+2, 1)
    for (auto x : xx) {
        if (has1.count(x) and has0.count(x-1) and has0.count(x+1)) {
            ans++;
        }
        if (has0.count(x) and has1.count(x-1) and has1.count(x+1)) {
            ans++;
        }
    }

    cout << ans << endl;
}

/*
Há tres maneiras de criar triângulos
1. Dois pontos (x, 0) e (x, 1), logo podemos pegar todos os n - 2 pontos e formar triângulos com o ângulo reto
2. Para todo ponto (x+1, 1), preciso ter dois pontos (x, 0) e (x+2, 0)
3. Para todo ponto (x+1, 0), preciso ter dois pontos (x, 1) e (x+2, 1)
*/

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc; while(tc--) solve();
}