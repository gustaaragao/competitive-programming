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

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int l, r, x, y, k;
    cin >> l >> r >> x >> y >> k;
    int a = l, b = x;
    double efic;
    while (a <= r and b <= y) {
        efic = (double) a / b;
        if (efic > k) b++;
        else if (efic < k) a++;
        else break;
    }
    if (efic == k) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << endl;
}

// a -> experienca -> l <= a <= r
// b -> custo  -> x <= b <= y
// eficiencia = a / b --> meu objetivo é encontrar um a, b tal que eficiencia = k

// Posso iniciar a = l, b = x --> aumentar o a até k >= 1