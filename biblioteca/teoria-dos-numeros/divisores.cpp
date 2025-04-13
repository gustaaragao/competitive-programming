#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

// Problema: Dado um numero N, queremos saber todos os divisores inteiros de N. (!= de fatoracao)
vector<int> divisores;

void obter_divisores(int n) {
    for (int i = 1; i * i <= n; i++) {
        if (n % i) continue; // i não é divisor

        // Se n/i = i, então i = sqrt(n). Tomamos cuidado neste caso
        // para não contar sqrt(N) duas vezes
        if (n / i == i) divisores.push_back(i);
        else divisores.push_back(i), divisores.push_back(n/i);
    }
    sort(divisores.begin(), divisores.end()); // Ordena os divisores
}