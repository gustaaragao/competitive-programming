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
    int l, c; cin >> l >> c;
    vector<vector<char>> matriz(l, vector<char>(c));

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            cin >> matriz[i][j];
        }
    }
    int n; cin >> n;
    vector<string> palavras(n);
    for (auto &x : palavras) cin >> x;
    
    vector<vector<set<int>>> acc(l, vector<set<int>>(c));

    for (int k = 0; k < n; k++) {
        string p = palavras[k];
        map<char, int> mp_p;
        for (auto c : p) mp_p[c]++;
        
        int m = p.size();
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < c; j++) {
                // Linha
                if (j + m <= c) {
                    map<char, int> mp_linha;
                    for (int ii = 0; ii < m; ii++) {
                        mp_linha[matriz[i][j+ii]]++;
                    }
                    bool ok = true;
                    for (auto &[k, v] : mp_p) {
                        if (mp_linha[k] != v) ok = false;
                    }
                    if (ok) {
                        for (int ii = 0; ii < m; ii++) {
                            acc[i][j+ii].insert(k);
                        }
                    }
                }
                // Coluna
                if (i + m <= l) {
                    map<char, int> mp_coluna;
                    for (int ii = 0; ii < m; ii++) {
                        mp_coluna[matriz[i+ii][j]]++;
                    }
                    bool ok = true;
                    for (auto &[k, v] : mp_p) {
                        if (mp_coluna[k] != v) ok = false;
                    }
                    if (ok) {
                        for (int ii = 0; ii < m; ii++) {
                            acc[i+ii][j].insert(k);
                        }
                    }
                }
                // Diagonal
                if (j + m <= c && i + m <= l) {
                    map<char, int> mp_diagonal;
                    for (int ii = 0; ii < m; ii++) {
                        mp_diagonal[matriz[i+ii][j+ii]]++;
                    }
                    bool ok = true;
                    for (auto &[k, v] : mp_p) {
                        if (mp_diagonal[k] != v) ok = false;
                    }
                    if (ok) {
                        for (int ii = 0; ii < m; ii++) {
                            acc[i+ii][j+ii].insert(k);
                        }
                    }
                }
                
                // swap(i, j); // RATARIA
                // swap(l, c); // RATARIA
                if (j - m + 1 >= 0 && i + m <= l) {
                    map<char, int> mp_diagonal;
                    for (int ii = 0; ii < m; ii++) {
                        mp_diagonal[matriz[i+ii][j-ii]]++;
                    }
                    bool ok = true;
                    for (auto &[k, v] : mp_p) {
                        if (mp_diagonal[k] != v) ok = false;
                    }
                    if (ok) {
                        for (int ii = 0; ii < m; ii++) {
                            acc[i+ii][j-ii].insert(k);
                        }
                    }
                }
                // swap(l, c); // RATARIA
                // swap(i, j); // RATARIA
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (acc[i][j].size() > 1) ans++;
        }
    }

    cout << ans << endl;
}