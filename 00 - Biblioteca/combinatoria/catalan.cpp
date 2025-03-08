#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

#define N_MAX 100

vector<ll> C(N_MAX + 1, -1);

// Com um long long é possível guardar até C[32] sem overflow
long long catalan(int n) {
    if (n == 0) return C[0] = 1; // Caso base
    if (C[n] != -1) return C[n];
    C[n] = (2*(2*n - 1)*catalan(n - 1))/(n + 1);
    return C[n];
}

int main() { _
    cout << catalan(6) << endl;
    return 0;
}
