#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

// Função para o Algoritmo Estendido de Euclides
int euclidesEstendido(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int mdc = euclidesEstendido(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return mdc;
}

int main() {
    int a, b, x, y;

    cout << "Digite os valores de a e b: ";
    cin >> a >> b;

    int mdc = euclidesEstendido(a, b, x, y);

    cout << "MDC(" << a << ", " << b << ") = " << mdc << endl;
    cout << "Coeficientes: x = " << x << ", y = " << y << endl;

    return 0;
}