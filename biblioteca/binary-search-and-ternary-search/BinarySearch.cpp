#include <bits/stdc++.h>
using namespace std;
int n, x;
bool possible(int m) { return true; }; // O(M)
// Retorna o primeiro elemento que valida nossa propriedade
// lower_bound -> primeiro valor >= x (Primeiro Verdadeiro (MINIMIZAR))
// O nosso f(x) precisa ser: [F, F, F, F, T, T, T, T], ele para quando encontrar o primeiro T.
int bs(int x) { // O(M*log(n))
    int ans = -1, l = 0, r = 1e18; // r = MAX
    while (l <= r) {
        int m = l + (r-l)/2; // Piso
        if (possible(m)) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return ans;
}
// Retorna o último elemento que valida nossa propriedade
// O nosso f(x) precisa ser: [T, T, T, T, F, F, F, F], ele para quando encontrar o último T.
int bs_last(int x) {
    int ans = -1, l = 0, r = 1e18; // r = MAX
    while (l <= r) {
        int m = l + (r-l)/2; // Teto (Último Verdadeiro (MAXIMIZAR))
        if (possible(m)) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return ans;
}