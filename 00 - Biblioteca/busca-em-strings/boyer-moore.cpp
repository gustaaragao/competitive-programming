#include <bits/stdc++.h>
using namespace std; 

// Função para criar a tabela de deslocamento para o algoritmo Boyer-Moore
vector<int> criar_tabela_deslocamento(const string &padrao) {
    int m = padrao.size();
    vector<int> tabela(256, m);

    for (int i = 0; i < m - 1; i++) {
        tabela[padrao[i]] = m - 1 - i;
    }

    return tabela;
}

// Função Boyer-Moore para busca de padrão em uma string
int boyer_moore(const string &texto, const string &padrao) {
    int n = texto.size();
    int m = padrao.size();

    if (m == 0) return -1;

    vector<int> tabela_deslocamento = criar_tabela_deslocamento(padrao);

    int i = m - 1; // Índice no texto
    while (i < n) {
        int j = m - 1; // Índice no padrão

        while (j >= 0 && texto[i] == padrao[j]) {
            i--;
            j--;
        }

        if (j < 0) {
            return i + 1; // Padrão encontrado, retorna o índice inicial
        }

        i += max(1, tabela_deslocamento[texto[i]]);
    }

    return -1; // Padrão não encontrado
}