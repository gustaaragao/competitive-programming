#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

#define N 200 
#define P 1000000007

vector<long long> fat(N);

long long fatorial(int n) {
    if (n == 0) return fat[0] = 1; // Caso Base: 0! = 1 -> O(1)
    if (fat[n] != 0) return  fat[n]; // fat[n] calculado -> O(1)
    return fat[n] = (n*fatorial(n - 1)) % P; // fat[n] nao calculado -> O(n)
}

template<typename T = char>
long long permutacao(const vector<T> &A) {
    map<T, int> hist;
    for (auto a : A) hist[a]++;
    long long ans = fatorial(A.size());
    for (auto [a, ni] : hist) ans /= fatorial(ni);
    return ans;
}

template<typename T = char>
long long permutacao_circular(const vector<T> &A) {
    // PC(n) = P(n - 1) = (n - 1)!
    return permutacao(A);
}

template<typename T = int>
void enumerar_permutacoes(vector<T> &A) {\
    sort(A.begin(), A.end()); // Primeira permutacao na ordem lexicografica
    // O(n*n!)
    do {
        for (int i = 0; i < A.size(); i++)
            cout << A[i] << (i + 1 == A.size() ? '\n' : ' ');
    } while (next_permutation(A.begin(), A.end()));
}

int main(){ _
    vector<char> s1 = {'M', 'E', 'S', 'A'};  
    cout << permutacao(s1) << endl;
    
    vector<char> s2 = {'C', 'A', 'S', 'A'};  
    cout << permutacao(s2) << endl;

    vector<int> v = {5, 3, 4};
    enumerar_permutacoes(v);

    return 0;
}