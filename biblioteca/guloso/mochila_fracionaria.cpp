#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int solve(vector<int> valor, vector<int> peso, int capacidade) {
    int n = valor.size(); 
    vector<double> razao(n);
    for (int i = 0; i < n; i++) razao[i] = (double) valor[i] / peso[i];
    // Ordenar os items em forma decrescente pela razao
    vector<int> indices(n);
    for (int i = 0; i < n; i++) indices[i] = i;
    sort(indices.begin(), indices.end(), [&](int i, int j) {
        return razao[i] > razao[j];
    });
    int cap_atual = capacidade, valor_total = 0;
    for (auto i : indices) {
        if (peso[i] <= cap_atual) {
            // O item i cabe inteiro na mochila
            cap_atual -= peso[i];
            valor_total += valor[i];
        } else {
            // O item i NAO cabe inteiro na mochila -> pegar uma fracao razao[i] do item
            valor_total += cap_atual * razao[i]; // cap_atual * (valor / peso) = valor para cap_atual
            cap_atual == 0;
            break;
        }
    }
    return valor_total;
}

int main() {
    vector<int> valor = {840, 600, 400, 100, 300}, peso = {40, 30, 20, 10, 20};
    cout << solve(valor, peso, 50) << endl;
    return 0;
}