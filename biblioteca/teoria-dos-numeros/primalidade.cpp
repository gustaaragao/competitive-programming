#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

// O(n)
bool primalidade_forca_bruta(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    for (int i = 2; i < n - 1; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// O(sqrt(n))
bool primalidade_otimizado(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    int limite = sqrt(n) + 1;
    for (int i = 3; i <= limite; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}