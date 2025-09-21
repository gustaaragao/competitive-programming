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
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool check_bit(int n, int pos) {
    int mask = 1 << pos;
    if ((n & mask) == 0) return false;
    return true;
}

signed main(){
    FAST_IO

    int n; cin >> n;
    vector<ll> a(n);
    vector<int> cnt(32, 0); // conta os bits ativos
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        for (int pos = 0; pos < 32; pos++) {
            if(check_bit(x, pos)) cnt[pos]++;
        }
        a[i] = x;
    }

    vector<ll> ans(n, 0);
    for (int i = 0; i < n; i++) {
        for (int pos = 0; pos < 32; pos++) {
            if (cnt[pos]) {
                ans[i] = ans[i] | (1 << pos);
                cnt[pos]--;
            }
        }
    }

    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
}

/*
bitset<numero_de_bits> x;

# Inicializar
bitset<32> x;        -> Por padrão, é 0
bitset<32> x(20);    -> 20
bitset<32> x('101'); -> 5

# Acessar bit (0-indexed)
x[i]      -> acessa o bit na posição i
x.test(i) -> acessa o bit na posição i

# Ativar, desativar e inverter bit
x.set(i)   -> ativa o bit na posição i
x.reset(i) -> desativa o bit na posição i
x.flip(i)  -> inverte o bit na posição i

# Operadores
&    ->  Bitwise AND

|    ->  Bitwise OR

^    ->  Bitwise XOR

>>=  ->  Binary Right shift and assign

<<=  ->  Binary Left shift and assign

&=   ->  Assign the value of bitwise AND to the first bitset.

|=   ->  Assign the value of bitwise OR to the first bitset.

^=   ->  Assign the value of bitwise XOR to the first bitset.

~    ->  Bitwise NOT

Exemplo:
// 18 = (10010)
bitset<5> bs1(18);
    
// 5 = (00101)
bitset<5> bs2(5);
*/