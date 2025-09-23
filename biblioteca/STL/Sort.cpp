#include <bits/stdc++.h>
using namespace std;
vector<int> v = {1, 2, 3, 4};
signed main() {
    // Ordenação CRESCENTE (Padrão)
    sort(v.begin(), v.end());
    // Ordenacação DECRESCENTE 
    sort(v.rbegin(), v.rend());
    // Ordenação CRESCENTE usando lambda
    sort(v.begin(), v.end(), [](int a, int b) {
        return a < b;
    });
    // Ordenação DECRESCENTE usando lambda
    sort(v.begin(), v.end(), [](int a, int b) {
        return a > b;
    });
    // Ordenação CRESCENTE usando função pronta
    sort(v.begin(), v.end(), less<int>());
    // Ordenação DECRESCENTE usando função pronta
    sort(v.begin(), v.end(), greater<int>());
    // Verificar se v[] está ordenado em ordem CRESCENTE
    if (is_sorted(v.begin(), v.end())) {
        cout << "v[] está ordenado em ordem CRESCENTE" << endl;
    }
    // Verificar se v[] está ordenado em ordem DECRESCENTE
    if (is_sorted(v.rbegin(), v.rend())) {
        cout << "v[] está ordenado em ordem DECRESCENTE" << endl;
    }
}
