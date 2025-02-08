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

    vector<pair<int, int>> botas(60 + 1, {0, 0}); // {E, D}

    while (n--) {
        int tam; cin >> tam;
        char pe; cin >> pe;
    
        if (pe == 'E') botas[tam].f++;
        else botas[tam].s++;
    }

    int resp = 0;

    for (int i = 0; i < botas.size(); i++) {
        resp += min(botas[i].f, botas[i].s); 
    }

    cout << resp << endl;

    return 0;
}