// O(nlog(n))
#include <bits/stdc++.h>
using namespace std; 

template<typename T = int>
void merge(vector<T> &vetor, vector<T> &vetor_aux, int i, int m, int j) {
    int i1 = i, i2 = m + 1, k = i;
    while (i1 <= m && i2 <= j) {
        if (vetor[i1] <= vetor[i2]) vetor_aux[k++] = vetor[i1++];
        else vetor_aux[k++] = vetor[i2++];
    }
    while (i1 <= m) vetor_aux[k++] = vetor[i1++];
    while (i2 <= j) vetor_aux[k++] = vetor[i2++];
    for (int x = i; x <= j; x++) vetor[x] = vetor_aux[x];
}

template<typename T = int>
void merge_sort(vector<T> &vetor, vector<T> &vetor_aux, int i, int j) {
    if (i < j) {
        int m = i + (j - i) / 2;
        merge_sort(vetor, vetor_aux, i, m);
        merge_sort(vetor, vetor_aux, m + 1, j);
        merge(vetor, vetor_aux, i, m, j);
    }
}