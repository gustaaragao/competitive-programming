#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

// Definição de tipo para uma tupla de três inteiros
typedef tuple<int, int, int> iii;

// Função para calcular o máximo divisor comum (MDC) usando o algoritmo de Euclides
int euclides(int a, int b) {
    while (b != 0) {
        int temp = b; // Variável temporária para armazenar o valor de b
        b = a % b;    // Atualiza b com o resto da divisão de a por b
        a = temp;     // Atualiza a com o valor antigo de b
    }
    return a; // Retorna o MDC
}

// Função para calcular o inverso modular de forma bruta
int inverso_mod_bruto(int a, int m) {
    if (euclides(a, m) != 1) { // Verifica se a e m são coprimos
        return -1; // Retorna -1 para indicar que não há inverso modular
    }
    a = a % m; // Reduz a ao intervalo [0, m-1]
    for (int x = 1; x < m; ++x) { // Testa todos os valores de x de 1 até m-1
        if ((a * x) % m == 1) { // Verifica se (a * x) ≡ 1 (mod m)
            return x; // Retorna o valor de x como o inverso modular
        }
    }
    return -1; // Retorna -1 se não encontrar o inverso modular
}

// Função para calcular o MDC e os coeficientes de Bézout usando o algoritmo de Euclides estendido
iii euclides_estendido(int a, int b) {
    if (a == 0) {
        return make_tuple(b, 0, 1); // Caso base: retorna o MDC e os coeficientes
    }
    int mdc, x1, y1; // Variáveis para armazenar o resultado recursivo
    tie(mdc, x1, y1) = euclides_estendido(b % a, a); // Chamada recursiva
    int x = y1 - (b / a) * x1; // Calcula o coeficiente x
    int y = x1; // Atualiza o coeficiente y
    return make_tuple(mdc, x, y); // Retorna o MDC e os coeficientes
}

// Função para calcular o inverso modular usando o algoritmo de Euclides estendido
int inverso_mod(int a, int m) {
    int mdc, x, y; // Variáveis para armazenar o MDC e os coeficientes de Bézout
    tie(mdc, x, y) = euclides_estendido(a, m); // Calcula o MDC e os coeficientes
    if (mdc != 1) { // Verifica se a e m são coprimos
        return -1; // Retorna -1 para indicar que não há inverso modular
    }
    return (x % m + m) % m; // Retorna o inverso modular no intervalo [0, m-1]
}