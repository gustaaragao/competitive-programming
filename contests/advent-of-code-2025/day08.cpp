#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int

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

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<tuple<int,int,int>> arr;
    string in;
    while (cin >> in) {
        vector<string> tokens = tokenizer(in, ",");
        arr.emplace_back(
            stoll(tokens[0]),
            stoll(tokens[1]),
            stoll(tokens[2])
        );
    }
    for (auto [x, y, z] : arr) {
        cout << x << " " << y << " " << z << endl;
    }
}