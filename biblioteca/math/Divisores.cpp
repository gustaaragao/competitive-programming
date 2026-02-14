#include <bits/stdc++.h>
using namespace std;
vector<int> divisores[100005]; 
signed main() {
    // Enumerar todos os divisores dos numeros de i até N
    int n; cin >> n;
    for (int i = 1; i <= n; i++) { // O(nlog(n))
        for (int j = i; j <= n; j += i) { // j -> múltiplo de i
            divisores[j].push_back(i);
        }
    }
}

/*
# Teorema Fundamental da Aritmética

Todo inteiro N > 1 pode ser representado de forma única (exceto pela ordem) como produto de números
primos.

N = (p1 ^ e1) * (p2 ^ e2) * ... * (pk ^ ek)

# Quantidade de Divisores

A quantidade de divisores de um número N, denotada por d(N), é calculada a partir de seus expoentes primos

d(N) = (e1 + 1)(e2 + 1)...(ek + 1)

Obs.: a qtd de divisores de N só é ímpar, se N for um QUADRADO PERFEITO!
*/
