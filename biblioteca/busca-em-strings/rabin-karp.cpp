#include <bits/stdc++.h>
using namespace std; 

// Função para calcular o hash de uma string
int calcular_hash(const string &str, int base, int primo) {
    int hash = 0;
    for (char c : str) {
        hash = (hash * base + c) % primo;
    }
    return hash;
}

// Função para implementar o algoritmo de Rabin-Karp
vector<int> rabin_karp(const string &texto, const string &padrao) {
    vector<int> ocorrencias;
    int n = texto.size();
    int m = padrao.size();
    if (m > n) return ocorrencias;

    int base = 256; // Base para o cálculo do hash (número de caracteres possíveis)
    int primo = 101; // Número primo para modular o hash

    // Calcula o hash do padrão e o hash inicial do texto
    int hash_padrao = calcular_hash(padrao, base, primo);
    int hash_texto = calcular_hash(texto.substr(0, m), base, primo);

    // Potência de base^(m-1) usada para atualizar o hash
    int h = 1;
    for (int i = 0; i < m - 1; i++) {
        h = (h * base) % primo;
    }

    // Percorre o texto para encontrar correspondências
    for (int i = 0; i <= n - m; i++) {
        // Verifica se os hashes coincidem
        if (hash_padrao == hash_texto) {
            // Verifica se as strings realmente coincidem
            if (texto.substr(i, m) == padrao) {
                ocorrencias.push_back(i);
            }
        }

        // Atualiza o hash para a próxima janela
        if (i < n - m) {
            hash_texto = (base * (hash_texto - texto[i] * h) + texto[i + m]) % primo;
            if (hash_texto < 0) {
                hash_texto += primo;
            }
        }
    }

    return ocorrencias;
}