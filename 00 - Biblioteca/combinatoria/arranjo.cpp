#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

long long arranjo(long long n, long long p) {
    if (n < p) return 0;
    long long ans = 1;
    for (long long i = 0; i <= p - 1; i++) ans *= (n - i);
    return ans;
}

int main() { _
    cout << arranjo(4, 2) << endl;
    return 0;
}