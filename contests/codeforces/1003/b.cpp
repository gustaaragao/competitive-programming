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

int skibidus(string s) {
    if (s.size() == 1) return 1;
    else {
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i + 1]) {
                return 1;
                // s[i] = s[i - 1];
                // s.erase(i, 1);
                // skibidus(s);
                // Caso role uma iteracao do skibidus, a string inteira vai se reduzir a apenas um char (pois podemos trocar)
            }
        }
        return s.length();
    }
}

int main(){ _

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        cout << skibidus(s) << endl;
    }

    return 0;
}