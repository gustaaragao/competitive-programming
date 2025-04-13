#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

void crivo(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    cout << "Números primos até " << n << ": ";
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int n; cin >> n;

    crivo(n);

    return 0;
}