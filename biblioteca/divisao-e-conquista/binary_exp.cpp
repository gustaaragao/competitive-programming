// O(log(n))
#include <bits/stdc++.h>
using namespace std; 

int binary_exp(int x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;
    if (n % 2 == 0) return binary_exp(x * x, n / 2); // PAR
    else return x * binary_exp(x, n - 1); // IMPAR
}