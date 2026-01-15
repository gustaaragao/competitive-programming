#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
signed main() {
    vector<int> a(5);
    iota(all(a), 0);
    // ordena aleatoriamente
    shuffle(all(a), rng);
    // gera valor aleatório de [0, x)
    cout << rng() % 10 << endl; // [0, 10)
    // valor aleatório entre [a, b]
    int r = uniform_int_distribution<int>(3, 99)(rng);
    cout << r << endl;
}