#include <bits/stdc++.h>
using namespace std; 

#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pi;

const ll MOD = 1e9 + 7;

int posicaoLSB(int x) {
    int pos = 0;
    while ((x & 1) == 0) {
        x = x >> 1;
        pos++;
    }
    return pos;
}

signed main(){
    FAST_IO

    int n, x, y; cin >> n >> x >> y;

    int lsb_obj = (n - 1); // 1 << (n - 1)
    int lsb_x = posicaoLSB(x);
    int lsb_y = posicaoLSB(y);
    if (lsb_x == lsb_y) {
        cout << lsb_obj - lsb_x << endl;
    } else {
        cout << n << endl;
    }
}

/* BITMASK
Todas essas operações valem para o y
x -> (x + 0) / 2 = x >> 1
x -> (x + 2^n) / 2 = x/2 + 2^(n-1) = x >> 1 ^ 1 << (n-1)

Logo,
x -> (x>>1) + 0 << (n-1) 
          ou
x -> (x>>1) + 1 << (n-1) 

y -> (y>>1) + 0 << (n-1) 
          ou
y -> (y>>1) + 1 << (n-1) 

Nosso objetivo é transformar (x, y) = (2^n-1, 2^n-1) = (1 << (n-1), 1 << (n-1)).

Note que independemente do ponto que seja ativado, sempre há o shift para direita
do x ou do y, e a segunda parte da operação vem da escolha entre o 0 ou 2^n.

Considere x = 0b100000, podemos operar em x 3 vezes, ou seja, x = 0b???100, onde
? pode ser 0 ou 1, devendo a nossa escolha para o lado "+ 0 << (n - 1)" do nosso
problema.

Logo, a solução do problema é o número de operações que levam os LSB's de x e de y
para os LSBs de (2^n-1, 2^n-1).

Porém, temos alguns casos:

1) LSB(x) == LSB(y), basta fazer resposta = LSB(2^(n-1)) - LSB(x)

2) LSB(x) != LSB(y), note que x e y fazem shifts simultaneamente, e isso é um problema.

Então, podemos pensar da seguinte maneira:
- Apagar o 1 << (n-1), o nosso objetivo, com n shifts. Por exemplo,
0b100000 --> (Após n shifts) --> 0b?????? (podemos substituir ? de tal maneira que chegaremos em x e y)

Você deve ter a ideia que o problema pode ser interpretado de duas maneiras:
- Levar (x, y) para o ponto (2^n-1, 2^n-1), ou
- Levar (2^n-1, 2^n-1) para o ponto (x, y).
*/