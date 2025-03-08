#include <bits/stdc++.h>
using namespace std;

vector<string> tokenizer(string s, string del = " ") {
    // Time: O(n) Space: O(1) 
    vector<string> tokens;
    
    int start, end = -1*del.size();
    do {
        start = end + del.size();
        end = s.find(del, start);
        tokens.push_back(s.substr(start, end - start));
    } while (end != -1);

    return tokens;
}

vector<string> simple_tokenizer(string s) {
    // Time: O(n) Space: O(n)
    vector<string> tokens;
    stringstream ss(s);
    string word;

    while (ss >> word) {
        tokens.push_back(word);
    }

    return tokens;
}

vector<string> adv_tokenizer(string s, char del) {
    // Time: O(n) Space: O(n)
    vector<string> tokens;
    stringstream ss(s);
    string word;

    while (!ss.eof()) { // .eof = END OF FILE
        getline(ss, word, del); // (canal da string, var que armazena, delimitador)
        tokens.push_back(word);
    }

    return tokens;
}