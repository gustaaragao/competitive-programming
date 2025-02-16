/* Counting Sort
- Estavel e O(n + k) -> n: tamanho do vetor | k: tamanho do alfabeto 
- Vale a pena quando k < nlog(n)
- O k pode ser calculado como "max(vetor) + 1"
- Nao funciona com numeros negativos
*/ 
#include <bits/stdc++.h>
using namespace std;

void counting_sort(vector<int> &v, vector<int> &v_ordenado, int k) {
    int n = v.size();
    // Vetor de contagem
    vector<int> c(k, 0);
    // Histograma
    for (int i = 0; i < n; i++) c[v[i]]++; 
    // Cada C[i] tem a posicao do elemento i no vetor ordenado
    for (int i = 1; i < k; i++) c[i] = c[i] + c[i - 1]; 
    for (int i = n - 1; i >= 0; i--) {
        v_ordenado[c[v[i]] - 1] = v[i]; 
        c[v[i]]--;
    }
}

// Counting Sort embutido que calcula o k pelo maior valor do vetor (in-place)
void counting_sort_enhanced(vector<int> &v) {
    int n = v.size(), k = *max_element(v.begin(), v.end()) + 1;
    vector<int> output(n), c(k, 0);
    for (int i = 0; i < n; i++) c[v[i]]++; 
    for (int i = 1; i < k; i++) c[i] = c[i] + c[i - 1]; 
    for (int i = n - 1; i >= 0; i--) {
        output[c[v[i]] - 1] = v[i]; 
        c[v[i]]--;
    }
    v = output;
}