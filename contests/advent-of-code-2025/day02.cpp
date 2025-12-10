#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define sz(x) (int) (x).size()

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

vector<int> pi(string s) {
    vector<int> p(s.size());
    for (int i = 1, j = 0; i < s.size(); i++) {
        while (j > 0 and s[i] != s[j]) j = p[j-1];
        if (s[i] == s[j]) j++;
        p[i] = j;
    }
    return p;
}

bool checkID(string &text) {
    int n = sz(text);
    if (n <= 1) return false;
    vector<int> p = pi(text);
    int len_period = n - p[n-1];
    if (n % len_period == 0 && p[n-1] > 0) {
        return true;
    }
    return false;
}

signed main() {
    int ans = 0LL;
    string in; cin >> in;
    vector<string> tokens = tokenizer(in, ",");
    for (string t : tokens) {
        vector<string> t_splited = tokenizer(t, "-");
        int start = atoll(t_splited[0].c_str()), end = atoll(t_splited[1].c_str());
        for (int x = start; x <= end; x++) {
            string text = to_string(x);
            if (checkID(text)) ans += x;
        }
    }
    cout << ans << endl;
}
