#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, q; cin >> n >> q;
    vector<int> v(n);
    for(auto& x : v)
        cin >> x;

    vector<long long> s(n+1);
    s[0] = 0;

    for(int i = 1; i <= n; i++){
        s[i] = v[i-1] + s[i-1];
    }

    while(q--){
        int a, b;
        cin >> a >> b;
        cout << s[b] - s[a-1] << endl;
    }

    return 0;
}
