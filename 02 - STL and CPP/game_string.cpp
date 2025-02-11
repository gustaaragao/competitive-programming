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

// TIMEOUT: B - Game with string

int main(){ _

    string s; cin >> s;
    int turno = 1;
    bool removeu;

    while (true) {
        if (s.empty()) {
            turno = !turno;
            break;
        }
        
        removeu = false;


        // Tenta remover
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i + 1]) {
                s.erase(i, 2); // Remove dois caracteres consecutivos
                turno = !turno;
                removeu = true;
                break;
            }
        }

        if (!removeu) {
            // Sai do loop se nenhuma remocao foi feita
            turno = !turno; // Como o jogador atual nao conseguia efetuar uma remocao, o anterior eh campeao
            break; 
        }
    }
    
    cout << (turno ? "Yes" : "No") << endl;

    return 0;
}