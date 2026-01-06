#include <bits/stdc++.h>
using namespace std;
vector<int> divisores[100005]; 
signed main() {
    // Enumerar todos os divisores dos numeros de i até N
    int n; cin >> n;
    for (int i = 1; i <= n; i++) { // O(nlog(n))
        for (int j = i; j <= n; j += i) { // j -> múltiplo de i
            divisores[j].push_back(i);
        }
    }
}