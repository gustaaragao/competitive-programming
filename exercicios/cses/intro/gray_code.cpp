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


string to_binary(uint16_t x, int size) {
    string s;
    for (int i = size - 1; i >= 0; i--) s += ((x >> i) & 1) ? '1' : '0';
    return s;
}

int main(){ _

    int n; cin >> n;
    uint16_t gray;
    for (int i = 0; i < (1 << n); i++) { // (1 << n) == 2^n
        gray = i ^ (i >> 1);
        cout << to_binary(gray, n) << endl;
    }

    return 0;
}