#include <bits/stdc++.h>
using namespace std;
int divisores(int x) {
    int ans = 0;
    for (int a = 1; a*a <= x; a++) {
        if (x % a == 0) {
            // Se a é um divisor de x, então a * b = x.
            // Logo, b = x/a também é um divisor de x.
            int b = x / a;
            ans++;
            if (a!=b) ans++;
        }
    }
    return ans;
}
signed main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cout << divisores(x) << endl;
    }
}