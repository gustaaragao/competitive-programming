#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> divisores(int n) { // O(sqrt(N))
    vector<int> ans;
    int up = (int) sqrt(n); // --> otimização
    // for (int a = 1; a <= up; a++) { --> otimização
    for (int a = 1; a*a <= n; a++) {
        if (n % a == 0) {
            int b = n / a;
            ans.push_back(a);
            if (a != b) ans.push_back(b);
        }
    }
    return ans;
}
