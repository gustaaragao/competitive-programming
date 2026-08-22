#include <bits/stdc++.h>
using namespace std;

#define endl '\n' //<< flush

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    int contador = 0;
    while (n != 0) {
        // mx -> maior dígito de n
        // temp -> uma cópia de n
        int mx = 0, temp = n;

        // Percorro todos os dígitos de n (sem alterar n)
        // e pego maior dígito
        while (temp != 0) {
            int digito = temp % 10;
            mx = max(mx, digito);
            temp = temp / 10;
        }

        n -= mx;
        contador++;
    }
    cout << contador << endl;
}
