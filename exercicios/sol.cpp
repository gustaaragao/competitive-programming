#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define sz(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cout << #x << " = " << x << endl

void solve(){
    int n, k; cin >> n >> k;
    if (k % 2 != 0) { // k é ímpar
        for (int i = 0; i < k; i++) {
            cout << n << " ";
        }
        cout << endl;
    } else { // k é par
        vector<int> ans(k);
        // skip -> a[skip] será o número que terá o bit i desligado
        // cnt -> qtd de ai que ignoramos/desligamos o bit
        int skip = 0, cnt = 0;
        for (int i = 29; i >= 0; i--) {
            if ((n >> i) & 1) { // o bit i está setado
                for (int j = 0; j < k; j++) {
                    if (j != skip) {
                        ans[j] |= (1LL << i);
                    }
                }
                skip++;
                skip%=k;
                cnt++;
            } else {
                cnt = min(k, cnt);
                int even = (cnt % 2 == 0) ? cnt : cnt-1;
                for (int j = 0; j < even; j++) {
                    ans[j] |= (1LL << i);
                }
            }
        }

        for (auto x : ans) cout << x << " ";
        cout << endl;
    }
}

/*
Se k é ímpar, podemos fazer todos os ai = n.

Se k é par, podemos construir o ai como o descrito:

Sempre que o bit j de n estiver ativo, podemos desativar o bit j em algum ai, e
ativar esse bit j nos outros k-1 a's.

Desativar esse bit garante que o que fizermos após esse bit não fará esse ai >= n.

Sempre que o bit j de n não estiver ativo, eu posso ativar para um número par de
a's o bit j.

n = 0b10110101
----------------
0b0xxxxxxxx
0b100xxxxx
0b1010xxxx
0b101100xx
*/

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc; while(tc--) solve();
}