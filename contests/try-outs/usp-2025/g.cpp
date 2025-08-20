#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
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

signed main(){ _

    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        if (c == '(') v[i] = 1;
        else v[i] = -1;
    }
    vector<int> prefix_sum(n), prefix_one(n);
    prefix_sum[0] = v[0];
    prefix_one[0] = (v[0] == 1) ? 1 : 0;
    for (int i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i-1] + v[i];
        prefix_one[i] = prefix_one[i-1];
        if (v[i] == 1) prefix_one[i]++;
    }
    int pos_zero = -1;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == -1 && pos_zero != -1) {
            ans += prefix_one[pos_zero];
        }
        if (prefix_sum[i] == 0) pos_zero = i;
    }
    cout << ans << endl;
}
/*
(((())))

v = 1, 1, 1, 1, -1, -1, -1, -1

prefix_sum = 1, 2, 3, 4, 3, 2, 1, 0

prefix_one = 1, 2, 3, 4, 4, 4, 4, 4

Se eu remover o par i = 1 e j = 6:

prefix_sum = 1, 2, 3, 4, 3, 2, 1, 0
		-  -  -  -  -  -  -  --> Remover v[i] = '('
			    +  +  +  --> Remover v[j] = ')'
		*  *  *  *  -----------> Somente i até j - 1 vai sofrer alteração,
					 caso algum prefix_sum[i..j-1] = 0, vai ficar negativo
					 o que sinaliza *desequilíbrio*.
Exemplo:
(()())()

(  (  )  (  )  )  (  )
1, 2, 1, 2, 1, 0, 1, 0

pos_zero = -1; 
ans = 0;
# Vamos percorrer a string, buscando prefix_sum[i] == 0 e quando pos_zero = 1
	if (v[i] == ')' && pos_zero = -1) {
		# Caso encontremos um v[i] == ')' e já tenhamos encontrado um prefix_sum[0..i] = 0,
		# podemos contabilizar todos os pares que desbalanceam a partir de todos os '(' encontrados em 0...pos_zero.
		ans += prefix_one[pos_zero];
	}
	
	if (prefix_sum[i] == 0) pos_zero = 0;

*/