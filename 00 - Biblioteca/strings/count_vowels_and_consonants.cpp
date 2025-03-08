#include <bits/stdc++.h>
using namespace std;

void count_vowels_and_consoants(const string& s) {
    string vogais = "aeiouAEIOU";

    int qtdVogais = 0, qtdConsoantes = 0;

    for (size_t i = 0; i < s.size(); i++) {
        if (vogais.find(s[i]) != string::npos) qtdVogais++;
        else qtdConsoantes++;        
    }

    cout << "Vogais: " << qtdVogais << " Consoantes: " << qtdConsoantes << "\n";
}