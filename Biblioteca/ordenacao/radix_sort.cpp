/* Radix Sort
- O(d * (n + b))
    -> d: numero de digitos
    -> n: tamanho do vetor
    -> b: tamanho da base do numero usado
- Ineficiente para conjuntos pequenos de dados
*/

#include <bits/stdc++.h>
using namespace std;

void couting_sort(vector<int> &v, int exp) { // Counting Sort Modificado para contar os digitos
    int n = v.size();
    vector<int> output(n);
    // Contagem de ocorrencia de cada digito
    vector<int> c(10, 0); 
    for (int i = 0; i < n; i++) c[(v[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) c[i] = c[i] + c[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[c[(v[i] / exp) % 10] - 1] = v[i];
        c[(v[i] / exp) % 10]--;
    }

    v = output;
}

void radix_sort(vector<int> &v) {
    if (v.empty()) return;
    int maior = *max_element(v.begin(), v.end());
    
    for (int exp = 1; maior / exp > 0; exp *= 10) {
        // Loop do menos significativo ate o mais significativo
        couting_sort(v, exp);
    }

}