#include <bits/stdc++.h>
using namespace std;

void upper(string& s) {
    transform(s.begin(), s.end(), s.begin(), ::toupper);
}

void lower(string& s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
}