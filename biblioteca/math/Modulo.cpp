#include <bits/stdc++.h>
using namespace std;
#define int long long
// Assuma que os inputs estão no range [0, MOD)
const int MOD = 1e9 + 7;
inline int add(int a, int b) {return ((a % MOD) + (b % MOD)) % MOD;}
inline int sub(int a, int b) {return ((a % MOD) - (b % MOD) + MOD) % MOD;}
inline int mult(int a, int b) {return ((a % MOD) * (b % MOD)) % MOD;}
inline int pow(int x, int y, int p) { // (x ^ y) % p
    int res = 1;
    x %= p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
// Calcular inverso modular: a^-1 
inline int inv(int a) {return pow(a, MOD - 2, MOD);}
inline int divi(int a, int b) {return mult(a, inv(b));}
signed main() {
    int a = 10, b = 20; // Substitua o MOD para 7
    cout << add(a, b) << endl; // 2
    cout << sub(a, b) << endl; // 4
    cout << mult(a, b) << endl; // 4
    cout << divi(a, b) << endl; // 4
}