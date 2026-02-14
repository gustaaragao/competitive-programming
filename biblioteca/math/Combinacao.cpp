#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
int comb[MAXN+1][MAXN+1];
// pre calculando as combinacoes -> O(n)
void pre() {
    comb[0][0] = 1;
    for (int n = 1; n <= MAXN; n++) {
        comb[n][0] = comb[n][n] = 1;
        for (int k = 1; k < n; k++) {
            comb[n][k] = comb[n-1][k-1] + comb[n-1][k];
        }
    }
}
signed main() {
    pre();
}
