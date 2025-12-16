#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define all(x) (x).begin(), (x).end()

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
    vector<pair<int, int>> ranges;
    int ans = 0LL;
    string in;
    while (cin >> in) {
        if (count(all(in), '-')) {
            vector<string> tokens = tokenizer(in, "-");
            int a = atoll(tokens[0].c_str()), b = atoll(tokens[1].c_str());
            ranges.emplace_back(a, b);
        } else {
            // sort(all(ranges));
            // int x = atoll(in.c_str());
            // sort(all(ranges));
            // for (auto [s, e] : ranges) {
            //     if (x >= s and x <= e) {
            //         ans++;
            //         break;
            //     }
            // }
        }
    }
    // cout << ans << endl;
    sort(all(ranges));

    vector<pair<int,int>> merged;

    for (auto &p : ranges) {
        if (merged.empty() || merged.back().second < p.first) {
            // Sem sobreposição
            merged.push_back(p);
        } else {
            // Existe sobreposição
            merged.back().second = max(merged.back().second, p.second);
        }
    }

    for (auto [s, e] : merged) {
        ans += e - s + 1;
    }
    cout << ans << endl;
}