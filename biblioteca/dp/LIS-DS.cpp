#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

typedef long long ll;

const ll MOD = 1e9 + 7;

// Coordinate Compreesion
void coordinate_compression(vector<int> &a) {
    set<int> s; // Conjunto para armazenar todos os números únicos
    for (auto x : a) s.insert(x);

    int index = 0;
    map<int, int> mp; // Map para armazenar os novos elementos
    
    set<int>::iterator itr;
    for (itr = s.begin(); itr != s.end(); itr++) {
        index++;
        mp[*itr] = index;
    }

    // Alterando o valor de a
    for (int i = 0; i < a.size(); i++) {
        a[i] = mp[a[i]];
    }
}

// BIT ou SegTree
struct fenw {
    int n;
    vector<int> bit;

    fenw() {}
    fenw(int size) {
        n = size;
        bit.assign(size + 1, 0);
    }
    // query do maior prefixo a[0...r]
    int qry(int r) {
        int ans = 0;
        for (int i = r + 1; i > 0; i -= i & -i) // i & -i retorna os bits menos signativos de i 
            ans = max(ans, bit[i]);
        return ans;
    }

    // atualiza o valor a[r] = x
    void upd(int r, int x) {
        for (int i = r + 1; i <= n; i += i & -i) 
            bit[i] = max(bit[i], x);
    }
};

// O(nlog(n))
int lis(vector<int> &a) {
    coordinate_compression(a);

    int n = a.size();

    fenw tree(n + 1);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int best = tree.qry(a[i] - 1);
        tree.upd(a[i], best + 1);
        ans = max(ans, best + 1);
    }

    return ans;
}

signed main(){ _

    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    cout << lis(a) << endl;
}

// https://cp-algorithms.com/sequences/longest_increasing_subsequence.html#solution-in-on-log-n-with-data-structures
// Considere t[a[i]] = dp[i] # dp[i] é o maior l de LIS t.q termina com a[i]
/* Para calcular dp[], precisamos fazer:
ans = -INF;
Para i = 0 até 0:
    dp[i] = max(t[0...a[i]] + 1) // Maior prefixo até a[i]
    ans = max(ans, dp[i])
    # O problema é buscar o maior prefixo de a[0..i] com a[k]  mudando, 
    sendo 0 <= k < i. --> SegTree ou BIT
    # Pontos Negativos da Solução
        - Implementação Complexa
        - a[i] for mt grande --> Coordinate Compression ou Dynamic SegTree
*/