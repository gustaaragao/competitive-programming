#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cerr << #x << " = " << x << endl
typedef long long ll;
typedef pair<int, int> pi;

#define PI acos(-1)

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a; cin >> a;
    if (a == 45) {
        cout << "Ambos";
    } else if (a < 45) {
        cout << "Costa";
    } else {
        cout << "Saad";
    }
    cout << endl;
}