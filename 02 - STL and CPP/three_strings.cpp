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

int main(){ _

    int n; cin >> n;
    
    string resp;

    while (n--) {
        string a, b, c; cin >> a; cin >> b; cin >> c;
        
        int tam = a.size();

        resp = "YES";

        for (int i = 0; i < tam; i++) {
            if (a[i] != c[i] && b[i] != c[i]) {
                resp = "NO";
                break;
            }
        }

        cout << resp << endl;
    }

    return 0;
}

/*
A = aaa
B = bbb
C = ccc

A = abc
B = bca
C = bca

aabb
bbaa
baba
*/