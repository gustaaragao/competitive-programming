#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-6; // Precisão -> defino as casas no setprecision
const int N_ITERATIONS = 100;
bool is_possible(long double m) {return true;}
long double bs(int x) {
    long double l = 0, r = 1e7;
    // for (int i = 0; i < N_ITERATIONS; i++) { -> Mais seguro
    while ((r - l) > EPS) {
        // Abaixo você pode ajustar para o problema
        long double m = l + (r-l)/2;
        if (is_possible(m)) l = m;
        else r = m;
    }
    cout <<  fixed << setprecision(6) << l << endl;
}