#include <bits/stdc++.h>
using namespace std;

template <typename T = int>
void insertion_sort(vector<T> &v) {
    for (int i = 1; i < v.size(); ++i) {
        T key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}