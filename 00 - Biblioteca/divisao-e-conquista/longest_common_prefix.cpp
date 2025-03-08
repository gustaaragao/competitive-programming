#include <bits/stdc++.h>
using namespace std; 

string common_prefix_merge(const string &s1, const string &s2) {
    string ans;
    int n1 = s1.length(), n2 = s2.length();
    for (int i = 0; i < n1 && i < n2; i++) {
        if (s1[i] != s2[i]) break;
        ans.push_back(s1[i]);
    }
    return ans;
}

string common_prefix(const vector<string> &v, int i, int j) {
    if (i == j) return v[i];
    if (i < j) {
        int meio = (i + j) / 2;
        string s1 = common_prefix(v, i, meio);
        string s2 = common_prefix(v, meio + 1, j);
        return common_prefix_merge(s1, s2);
    }
    return "";
}

string lcp(const vector<string> &v) {
    return common_prefix(v, 0, v.size() - 1);
}