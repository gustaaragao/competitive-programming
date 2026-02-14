#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+10;
bool primo[MAXN];
// Crivo até raiz de N --> Para descobrir todos os primos até N, basta achar
// todos os primos que não ultrapassam N
void crivo() { // O(nlog(log(n)))
    for (int i = 0; i < MAXN; i++) primo[i] = true;
    primo[0] = primo[1] = false;
    for (int i = 2; i * i < MAXN; i++) {
        if (primo[i] and (long long) i * i < MAXN) {
            for (int j = i * i; j < MAXN; j += i) {
                primo[j] = false;
            }
        }
    }
}
// Crivo até N 
// Útil quando queremos fatorar números até MAXN²
void crivo() {
    for (int i = 0; i < MAXN; i++) primo[i] = true;
    primo[0] = primo[1] = false;
    for (int i = 2; i < MAXN; i++) {
        if (primo[i]) {
            // i é primo
            if ((long long) i * i < MAXN) {
                for (int j = i*i; j < MAXN; j+=i) {
                    primo[j] = false;
                }
            }
        }
    }
}
// https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html#implementation
