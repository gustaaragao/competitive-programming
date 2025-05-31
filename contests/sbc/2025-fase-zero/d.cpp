#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define all(x) (x).begin(), (x).end()

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> ii;

const ll P = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

    int n; cin >> n;
    string s, t; cin >> s >> t;
    int qtd_colapsaram = 0, qtd_superposicao_isolado = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            if (t[i] == '0' || t[i] == '1') qtd_colapsaram++;
            qtd_superposicao_isolado++;
        }
    }
    cout << fixed << setprecision(2) << (double) qtd_colapsaram / qtd_superposicao_isolado << endl;
    return 0;
}