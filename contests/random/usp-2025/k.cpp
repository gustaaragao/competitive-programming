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
    int n; cin >> n;
    int a, b; cin >> a >> b;

    vector<bool> nao_gosta(a+1, false);
    for (int i = 0; i < b; i++) {
        int x; cin >> x;
        nao_gosta[x] = true;
    }

    for (int i = 1; i <= n; i++) {
        int m; cin >> m;
        int ruins = 0;
        for (int j = 0; j < m; j++) {
            int ing; cin >> ing;
            if (nao_gosta[ing]) ruins++;
        }

        if (3 * ruins - m > 0) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}

/*
orig  ruins

orig = ruins + resto
        > 1/3 orig

Logo, ruins > 1/3 orig
         3r > o
     3r - o > 0
*/