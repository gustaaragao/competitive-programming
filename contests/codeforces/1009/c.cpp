#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second

void solve() {
    int x; cin >> x;
    auto msb = [](int n) {
        if (n == 0) return -1;
        int pos = 0;
        while (n >>= 1) {
            pos++;
        }
        return pos;
    };

    int M = msb(x);
    
    int y = 0;
    // copia bits de x exceto o MSB
    for (int i = M-1; i >= 0; i--) {
        if ((x >> i) & 1) {
            y |= (1 << i);
        }
    }
    
    // adiciona um bit que x NÃO tem
    for (int i = 0; i < M; i++) {
        if (((x >> i) & 1) == 0) {
            y |= (1 << i);
            break;
        }
    }

    int c = y ^ x;

    if (
        (y > 0) and (y < x) and (x + y > c)
        and (x + c > y) and (y + c > x) 
    ) {
        cout << y << endl;
    } else {
        cout << "-1" << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc; while(tc--) solve();
}