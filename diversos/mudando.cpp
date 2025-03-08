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

/*
v = {8, 26, 15, 23, 65, 19, 2}
v_ordenado = {2, 8, 15, 19, 23, 26, 65}
v_resposta = {1, 5, 2, 4, 6, 3, 0}

Levar os valores de v para o indice que eles ocupam caso v estiver ordenado.
*/

int main(){ _

    int n; cin >> n;

    vector<int> v(n), ov(n);

    for (int i=0; i<n; i++) {
        cin >> v[i];
        ov[i] = v[i];
    }

    sort(ov.begin(), ov.end());
    
    map<int, int> idx;
    for (int i = 0; i < n; i++) {
        idx[ov[i]] = i;        
    }

    for (int i = 0; i < n; i++) {
        v[i] = idx[v[i]];
    }

    return 0;
}