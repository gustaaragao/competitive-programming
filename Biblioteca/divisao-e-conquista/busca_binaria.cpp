// O(log(n))
#include <bits/stdc++.h>
using namespace std; 

template<typename T = int>
int busca_binaria(const vector<T> &v, const T &alvo) {
    int esq = 0, dir = v.size() - 1;
    while (esq <= dir) {
        int meio = (esq + dir) / 2;
        if (v[meio] == alvo) return meio;
        else if (v[meio] > alvo) dir = meio - 1;
        else esq = meio + 1; 
    }
    return -1;
}