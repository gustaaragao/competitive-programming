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

    string s;
    
    char resp;

    while (n--) {
        cin >> s;
        
        resp = 'O';

        if (s.size() > 1) {
            for (int i = 1; i < s.size(); i++) {
                if ((int) (tolower(s[i]) - 'a') <= (int) (tolower(s[i - 1]) - 'a')) {
                    resp = 'N';
                    break;
                }
            }
        }

        cout << s << ": " << resp << endl;
    }

    return 0;
}