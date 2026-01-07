#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n, s; cin >> n >> s;
    vector<int> a(n);
    // [L, R] é BOM, então todos segmentos contidos também são bons
    // Exemplo: Maior segmento com soma <= s
    int l = 0, x = 0, ans = LLONG_MIN;
    for (int r = 0; r < n; r++) {
        x += a[r];
        while (x > s) {
            x -= a[l];
            l++;
        }
        if (x <= s) {
            ans = max(ans, r - l + 1);
        }
    }
    // [L, R] é BOM, então todos segmentos que o contém também são bons
    int l = 0, x = 0, ans = LLONG_MAX;
    for (int r = 0; r < n; r++) {
        x += a[r];
        while (x - a[l] >= s) {
            x -= a[l];
            l++;
        }
        if (x >= s) {
            ans = min(ans, r - l + 1);
        }
    }
    // Exemplo: Menor segmento com soma >= s
}
/*
Encontrar MAIOR ou MENOR segmento BOM ou contar a qtd de segmentos BONS.
Todos os problemas parecem com o seguinte pseudocodigo:
L = 0
for R = 0...n-1: // Segmento que termine em R
    add(a[R])
    while not good(): // Enquanto não for melhor ou suficiente
        remove(a[L])
        L++
    if (good()):
        ... // modifique a resposta

basta você modificar add(), good() e remove()

*/