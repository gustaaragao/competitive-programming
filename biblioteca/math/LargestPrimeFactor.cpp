#include <bits/stdc++.h>
using namespace std;
// É possível encontrar o maior fator primo de um número
// a partir da conjectura de 'Twin Primes'
int main() {
    int n; cin >> n;
    int ans = -1;
    while (n % 2 == 0) {
        n /= 2;
        ans = 2;
    }
    while (n % 3 == 0) {
        n /= 3;
        ans = 3;
    }
    for (int i = 5; i*i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            ans = i;
        }
        while (n % (i + 2) == 0) {
            n /= (i + 2);
            ans = (i + 2);
        }
    }
    if (n > 4) ans = n;
    cout << ans << endl;
}
