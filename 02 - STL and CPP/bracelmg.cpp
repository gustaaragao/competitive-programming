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

    string padrao, brac;

    string temp, reverse_temp;
    char resp;
    while (n--) {
        cin >> padrao; cin >> brac;
        
        resp = 'N';

        for (int i = 0; i < brac.size(); i++) {
            temp = "";
            
            for (int j = i; j < (i + padrao.size()); j++) {
                temp += brac[j % brac.size()];
            }
            
            reverse_temp = temp;
            reverse(reverse_temp.begin(), reverse_temp.end());

            if (temp == padrao || reverse_temp == padrao) {
                resp = 'S';
                break;
            }
        }

        cout << resp << endl;
    }
    return 0;
}