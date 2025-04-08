#include <bits/stdc++.h>
using namespace std; 

// Função para calcular o array LPS (Longest Prefix Suffix)
void calcular_lps(const string &padrao, vector<int> &lps) {
    lps[0] = 0; // lps[0] é sempre 0
    int comprimento = 0; // comprimento do prefixo mais longo
    int i = 1;

    while (i < padrao.size()) {
        if (padrao[i] == padrao[comprimento]) {
            comprimento++;
            lps[i] = comprimento;
            i++;
        } else {
            if (comprimento != 0) {
                comprimento = lps[comprimento - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Função para executar o algoritmo KMP
void kmp(const string &texto, const string &padrao) {
    int n = texto.size();
    int m = padrao.size();

    vector<int> lps(m);
    calcular_lps(padrao, lps);

    int i = 0; // índice para o texto
    int j = 0; // índice para o padrão

    while (i < n) {
        if (padrao[j] == texto[i]) {
            i++;
            j++;
        }

        if (j == m) {
            j = lps[j - 1];
        } else if (i < n && padrao[j] != texto[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}