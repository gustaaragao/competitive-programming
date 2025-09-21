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

bool check(const vector<vector<int>> &m, int n) {
    // Linhas
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (m[i][j-1] < m[i][j]) continue;
            else {
                return false;
            }
        }
    }
    // Colunas
    for (int j = 0; j < n; j++) {
        for (int i = 1; i < n; i++) {
            if (m[i-1][j] < m[i][j]) continue;
            else {
                return false;
            }
        }
    }

    return true;
}

// Rotacionar em 90 graus no sentido ANTI-HORÁRIO
void rotate(vector<vector<int>> &m, int n) {
    // Inverte as linhas i
    for (int i = 0; i < n; i++) {
        reverse(all(m[i]));
    }
    
    // Fazer a transposta da matriz
    for (int i = 0; i < n; i++) {
        // Comece j a partir de i+1 para evitar a diagonal e a parte inferior
        for (int j = i + 1; j < n; j++) {
            swap(m[i][j], m[j][i]);
        }
    }
}

signed main(){
    FAST_IO
    int n; cin >> n;
    vector<vector<int>> m(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }

    int ans = 0;
    while (!check(m, n)) {
        rotate(m, n);
        ans++;
    }
    cout << ans << endl;
}