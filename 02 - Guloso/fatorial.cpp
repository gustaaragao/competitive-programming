#include <bits/stdc++.h>

using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    int n; cin >> n;

    // Passo 1: Calcular o fatorial -> Memorization 
    vector<int> fat(11); // 10! > 10**5 (que eh o limite do N no problema)
    fat[0] = 1;
    for (int i = 1; i <= 10; i++) fat[i] = fat[i - 1] * i;

    int acc = 0;
    for (int i = 10; i > 0; i--) {
        // Buscar quantos vezes cabe fat[i] em n -> Buscando o melhor valor localmente, ou seja, um for invertido
        int quantasVezesCabe = n / fat[i];
        acc += quantasVezesCabe;
        n -= fat[i] * quantasVezesCabe;
    }

    cout << acc << endl;

    return 0;
}