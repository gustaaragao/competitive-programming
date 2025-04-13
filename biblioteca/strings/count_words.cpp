#include <bits/stdc++.h>
using namespace std;

map<string, int> count_words(const string& s) {
    map<string, int> mp;
    
    stringstream ss(s);
    string word;

    while (ss >> word) {
        // lower(word); // WORD == word
        
        mp[word]++;
    }

    return mp;
}