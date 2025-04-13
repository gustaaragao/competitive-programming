#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str = "Hello World";

    stringstream ss(str);
    string word;

    while (ss >> word) {
        
        cout << word;
    
    }
}