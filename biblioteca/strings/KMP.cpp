#include <bits/stdc++.h> 
using namespace std;

// n = |padrao| e m = |texto|
// pi: O(n)   match: O(n + m)   automato: O(|sigma| * n)

// Funcao de prefixo pi(i):
// Para todo prefixo s' de s, a funcao calcula o tamanho do maior
// do prefixo proprio de s' que também é sufixo.
vector<int> pi(string s) {
    vector<int> p(s.size());
    for (int i = 1, j = 0; i < s.size(); i++) {
        while (j > 0 and s[i] != s[j]) j = p[j-1];
        if (s[i] == s[j]) j++;
        p[i] = j;
    }
    return p;
}

// t -> texto, s -> padrão
// A função retorna a quantidade de matchings
vector<int> matching(string &t, string& s) {
    // '$' é um caracter impossível no padrão,
    // serve para não tratar o caso de quando acaba o matching
    vector<int> p = pi(s+'$'), match;
    for (int i = 0, j = 0; i < t.size(); i++) {
        while (j > 0 and t[i] != s[j]) j = p[j-1];
        if (t[i] == s[j]) j++;
        if (j == s.size()) match.push_back(i-j+1);
    }
    return match;
}

vector<int> autKMP(string &s) {

}

vector<int> matchingAut(string &t, string &s) {
    vector<int> match;
    return match;   
}