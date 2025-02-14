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
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    
    int m; cin >> m;
    vector<int> B(m);
    for (int i = 0; i < m; i++) cin >> B[i];
    
    int soma;

    for (auto a : A) {
        for (auto b : B) {
            soma = a + b;
            if (count(A.begin(), A.end(), soma) == 0 && count(B.begin(), B.end(), soma) == 0) {
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }

    return 0;
}