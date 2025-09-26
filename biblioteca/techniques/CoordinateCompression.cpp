#include <bits/stdc++.h>
using namespace std;
// Considere que 1 <= ai <= 10^9 e 1 <= |a| <= 10^5.
// Vamos comprimir os valores de ai para  [0, 10^5-1]. -> 0-INDEXED
void coordinate_compression(vector<int> &a) {
    set<int> s; // Conjunto para armazenar todos os números únicos
    for (auto x : a) s.insert(x);

    int index = 0;
    map<int, int> mp; // Map para armazenar os novos elementos
    
    set<int>::iterator it;
    for (it = s.begin(); it != s.end(); it++) {
        mp[*it] = index;
        index++;
    }

    // Alterando o valor de a
    for (int i = 0; i < a.size(); i++) {
        a[i] = mp[a[i]];
    }
}