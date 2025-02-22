#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

/*
int (32 bits) -> cabe até 12!
long long (64 bits) -> cabe até 20!
*/
#define N 100
#define P 1000000007

vector<long long> fat(N);

long long fatorial(int n) {
    if (n == 0) return fat[0] = 1; // Caso Base: 0! = 1 -> O(1)
    if (fat[n] != 0) return fat[n]; // fat[n] calculado -> O(1)
    return fat[n] = (n*fatorial(n - 1)) % P; // fat[n] nao calculado -> O(n)
}

int main(){ _
    int n; cin >> n;    
    cout << fatorial(n) << endl;
    return 0;
}