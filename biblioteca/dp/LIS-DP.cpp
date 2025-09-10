#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()


#define MAXN 1000

int dp[MAXN + 1];   
int p[MAXN + 1];    // Serve para exibir a solução

// O(n²) --> Solução não tão legal
// dp[i] --> é o tamanho l da LIS que termina com a[i]
// solução é max(d[i])
signed main(){ _
    
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    for (int i = 0; i < n; i++) {
        dp[i] = 1; p[i] = -1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && dp[i] < dp[j] + 1){
                // dp[i] = max(dp[i], dp[j] + 1);
                dp[i] = dp[j] + 1;
                p[i] = j;
            }
        }
    }

    int ans = dp[0], pos = 0;
    for (int i = 1; i < n; i++) {
        if (ans < dp[i]) {
            // ans = max(ans, dp[i]);
            ans = dp[i];
            pos = i;
        }
    }

    // Mostrando a solucao
    cout << ans << endl;

    // Exibindo a subsequencia da solucao
    vector<int> subseq;
    while (pos != -1) {
        subseq.push_back(a[pos]);
        pos = p[pos];
    }

    reverse(all(subseq));
    for (auto x : subseq) {
        cout << x << " ";
    }
    cout << endl;
}

/*
Considere uma array a[n]. 

Problema: Nosso objetivo é encontrar a maior subsequência estritamente crescente de a.

Subproblema: Vamos considerar que dp[k] é o tamanho da maior subsequencia que termina no índice k.

- dp[k] = {i1, i2, ..., ik} é a resposta para esse subproblema.

- i1 < i2 < ... < ik  --> a[i1] < a[i2] < ... < a[ik]

Logo, a resposta do nosso Problema é max(dp[])!

dp[i] = 1, se a subsequência for {a[i]}
       = max(dp[j] + 1), para j < i e a[j] < a[i]

dp[i] = max(1, max(d[j] + 1)), onde j < i e a[j] < a[i]
*/