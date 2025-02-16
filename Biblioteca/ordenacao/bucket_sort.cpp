#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<double> &bucket) {
    for (int i = 1; i < bucket.size(); ++i) {
        double key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

void bucket_sort(vector<double> &v) {
    int n = v.size();
    vector<double> b[10]; // vetor de listas encadeadas
    // Preencher os buckets
    for (int i = 0; i < n; i++) {
        int bi = v[i] * 10;
        b[bi].push_back(v[i]);
    }
    // Ordenar cada bucket
    for (int i = 0; i < 10; i++) insertion_sort(b[i]);
    // Concatenar buckets
    int i_atual = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < b[i].size(); j++) {
            v[i_atual] = b[i][j];
            i_atual++;
        } 
    }
}

#define endl '\n'

int main() {
    vector<double> v = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};

    bucket_sort(v);

    for (auto i : v) cout << i << endl;

    return 0;
}