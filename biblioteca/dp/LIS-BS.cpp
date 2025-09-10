#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

// O(n*log(n)) --> Solução TOP
// dp[l] --> é o menor a[i] que a maior LIS de tamanho l termina 
// solução é maior l t.q d[l] não é INF
// Obs.: Essa solução não serve para contar o número de LIS da a[], precisa usar lis-ds.

// int lis(vector<int> const& a) {
vector<int> lis(vector<int> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> dp(n + 1, INF);
    vector<int> id_dp(n + 1, -1);       // Armazena o índice i do valor dp[l] = a[i] 
    vector<int> previous(n + 1, -1);    // Armazena o índice do dp[l - 1]

    dp[0] = -INF;

    for (int i = 0; i < n; i++) {
        // Solução trivial
        // for (int l = 1; l <= i; l++) {
        //     if (dp[l-1] < a[i] && a[i] < dp[l]) {
        //         dp[l] = a[i];
        //     }
        // }
        
        // dp é estritamente crescente e a[i] atualiza apenas um valor de dp[l] 
        // dp[l - 1] < a[i] < dp[l] --> Podemos encontrar o l a partir da Busca Binária
        int l = upper_bound(all(dp), a[i]) - dp.begin();
        if (dp[l-1] < a[i] && a[i] < dp[l]) {
            dp[l] = a[i];
            id_dp[l] = i;
            previous[i] = id_dp[l-1];
        }
    }

    int ans = 0;
    for (int l = 0; l <= n; l++) {
        if (dp[l] < INF) ans = l;
    }
        
    // Apenas retornar a resposta
    // return ans;

    // Reconstruir a subsequência
    vector<int> subseq;

    int pos = id_dp[ans];
    while (pos != -1) {
        subseq.push_back(a[pos]);
        pos = previous[pos];
    }

    reverse(all(subseq));
    return subseq;
}

signed main(){ _
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    // int ans = lis(a);
    // cout << ans << endl;

    vector<int> ans = lis(a);
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
}

/* https://cp-algorithms.com/sequences/longest_increasing_subsequence.html
Considere uma array a[n]. 

Problema: Nosso objetivo é encontrar a maior subsequência estritamente crescente de a.

Subproblema: Vamos considerar que dp[l] é menor valor que um subsequência estritamente crescente de tamanho l termina.

- dp[0] = -INF (Caso base)

Vamos iniciar dp[l] = INF e vamos processar cada a[i] com 0 <= i <= n

Exemplo: a = {8, 3, 4, 6, 5, 2, 0, 7, 9, 1}

prefix = {}                             --> d = {-INF, INF, INF, ..., INF}
prefix = {8}                            --> d = {-INF, 8, INF, ..., INF}
prefix = {8, 3}                         --> d = {-INF, 3, INF, ..., INF}
prefix = {8, 3, 4}                      --> d = {-INF, 3, 4, ..., INF}
prefix = {8, 3, 4, 6}                   --> d = {-INF, 3, 4, 6, ..., INF}
prefix = {8, 3, 4, 6, 5}                --> d = {-INF, 3, 4, 5, ..., INF}
prefix = {8, 3, 4, 6, 5, 2}             --> d = {-INF, 2, 4, 5, ..., INF}
prefix = {8, 3, 4, 6, 5, 2, 0}          --> d = {-INF, 0, 4, 5, ..., INF}
prefix = {8, 3, 4, 6, 5, 2, 0, 7}       --> d = {-INF, 0, 4, 5, 7, ..., INF}
prefix = {8, 3, 4, 6, 5, 2, 0, 7, 9}    --> d = {-INF, 0, 4, 5, 7, 9, ..., INF}
prefix = {8, 3, 4, 6, 5, 2, 0, 7, 9, 1} --> d = {-INF, 0, 1, 5, 7, 9, ..., INF}

Quando vamos fazer d[l] = a[i]?
- Quando tiver nenhuma lis de tamanho l que termine em a[i]
- E, se não tiver nenhuma outra lis de tamanho l que termina em algum número menor que a[i]

Note que há uma sub-estrutura ótima do problema, a solução para l pode ser construída a partir de l - 1

dp[l] = -INF, se l = 0
        min(a[i], d[l]), se a[i] > d[l - 1] 
        +INF, caso contrário.
*/