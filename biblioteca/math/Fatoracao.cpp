#include <bits/stdc++.h>
using namespace std;
map<int, int> fatorar(int n) { // O(sqrt(n))
    map<int, int> exp;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            exp[i]++;
            n /= i;
        }
    }
    if (n > 1) exp[n]++;
    return exp;
}
