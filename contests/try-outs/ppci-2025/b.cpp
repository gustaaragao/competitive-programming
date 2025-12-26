#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int hp = n;
    bool ok = false;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == 20) {
            hp -= 2;
        } else if (x >= 15 and x < 20) {
            hp -= 1;
        } else {
            continue;
        }

        if (hp <= 0) {
            ok = true;
            break;
        }
    }
    cout << (ok ? "O BRUTO FOI DERROTADO" : "O BRUTO ESTA VIVO TPK PARA O GRUPO") << endl;
}