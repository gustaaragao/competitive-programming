// O(nlog(n))
#include <bits/stdc++.h>
using namespace std; 

template<typename T = int>
int count_and_merge(vector<T> &vetor, int i, int m, int j) {
    int n1 = m - i + 1, n2 = j - m;
    vector<T> esq(n1), dir(n2);
    for (int k = 0; k < n1; k++)
        esq[k] = vetor[i + k];
    for (int k = 0; k < n2; k++)  // Correção: k < n2
        dir[k] = vetor[m + 1 + k];
    
    int ans = 0;
    int i1 = 0, i2 = 0, k = i;
    while (i1 < n1 && i2 < n2) {
        if (esq[i1] <= dir[i2])
            vetor[k++] = esq[i1++];
        else {
            vetor[k++] = dir[i2++];
            ans += (n1 - i1);
        }
    }
    while (i1 < n1)
        vetor[k++] = esq[i1++];
    while (i2 < n2)
        vetor[k++] = dir[i2++];
    return ans;
}

template<typename T = int>
int count_inv(vector<T> &vetor, int i, int j) {
    int ans = 0;
    if (i < j) {
        int m = i + (j - i) / 2;
        ans += count_inv(vetor, i, m);
        ans += count_inv(vetor, m + 1, j);
        ans += count_and_merge(vetor, i, m, j);
    }
    return ans;
}

template<typename T = int>
int inversion_index(vector<T> &vetor) {
    int n = vetor.size();
    return count_inv(vetor, 0, n - 1);
}

int main() {
    vector<int> v = {4, 3, 2, 1};
    cout << inversion_index(v) << '\n';
    return 0;
}
