#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

vector<int> fatoracao;

void fatorar(int n) {
    for (int i = 2; i*i <= n; i++) {
    	while (n % i == 0) {
    		fatoracao.push_back(i);
    		n /= i;
    	}
    }

    // se o número resultante é primo, adicionamos ele
    if (n > 1) fatoracao.push_back(n);
}