#include <bits/stdc++.h>
using namespace std;
// Considere que 1 <= ai <= 10^9 e 1 <= |a| <= 10^5.
// Vamos comprimir os valores de ai para  [0, 10^5-1]. -> 0-INDEXED
map<int, int> coord; // mantem a propriedade de ordenacao dos valores
void coordinate_compression(vector<int> &v) {
    set<int> s; for (auto x : v) s.insert(x);
    int idx = 0;
    for (auto x : s) {
        coord[x] = idx;
        idx++;
    }
    for (int i = 0; i < v.size(); i++) {
        v[i] = coord[v[i]];
    }
}