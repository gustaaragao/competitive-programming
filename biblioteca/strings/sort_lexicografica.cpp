#include <bits/stdc++.h>
using namespace std;

void sort_lexicografica(vector<string>& v) {
    sort(v.begin(), v.end());
}

void sort_anti_lexicografica(vector<string>& v) {
    sort(v.begin(), v.end(), std::greater<std::string>());
}