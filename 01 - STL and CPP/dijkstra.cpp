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

    string joia;

    set<string> tesouro;

    // Uma abordagem para quando o problema nao tem o numero de linhas no caso de teste
    while(cin >> joia) {
        tesouro.insert(joia);
    }

    cout << tesouro.size() << endl;

    return 0;
}