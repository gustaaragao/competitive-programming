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
    vector<pair<int,int>> arr;
    string in;
    while (cin >> in) {
        vector<string> tokens = tokenizer(in, ",");
        int x = atoll(tokens[0].c_str()), y = atoll(tokens[1].c_str());
        arr.push_back({x, y});
    }
    int n = (int) arr.size(), ans = 0;
    for (int i = 0; i < n; i++) {
        auto [x1, y1] = arr[i];
        for (int j = i+1; j < n; j++) {
            auto [x2, y2] = arr[j];
            int dx = abs(x1 - x2) + 1, dy = abs(y1 - y2) + 1;
            ans = max(ans, dx * dy);
        }
    }
    cout << ans << endl;
}