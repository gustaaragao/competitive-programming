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

    map<char, int> mp;
    
    string s; cin >> s;  
    for (int i = 0; i < n; i++) {
        mp[s[i]]++;
    }

    int ones = min({mp['o'], mp['n'], mp['e']});
    int zeros = min({mp['z'], mp['e'] - ones, mp['r'], mp['o'] - ones});

    for (int i = 0; i < ones; i++) cout << "1 ";
    for (int i = 0; i < zeros; i++) cout << "0 ";
    cout << endl;

    return 0;
}