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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

    int n; cin >> n;
    vector<ll> arr(n); for (int i = 0; i < n; i++) cin >> arr[i];

    ll ans = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            ll diff = arr[i - 1] -  arr[i];
            ans += diff;
            arr[i] += diff;
        }
    }

    cout << ans << endl;

    return 0;
} 