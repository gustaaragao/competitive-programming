#include <bits/stdc++.h>
using namespace std;
int n, x;
bool possible(int m) { return true; }; // O(M)
// Retorna o primeiro elemento que valida nossa propriedade
// lower_bound -> primeiro valor >= x (Primeiro Verdadeiro (MINIMIZAR))
int bs(int x) { // O(M*log(n))
    int l = 0, r = n; // r = MAX
    while (l < r) {
        int m = l + (r-l)/2; // Piso
        if (possible(m)) r = m;
        else l = m + 1;
    }
    if (l == n) return -1;
    return l;
}
// Retorna o último elemento que valida nossa propriedade
int bs_last(int x) {
    int l = -1, r = n; // r = MAX
    while (l < r) {
        int m =  l + (r-l+1)/2; // Teto (Último Verdadeiro (MAXIMIZAR))
        if (possible(m)) l=m;
        else r=m-1;
    }
    return l; // Caso não encontre, retorna -1
}