#include <bits/stdc++.h>
using namespace std;

vector<int> occurrences_substring(const string& s,const string& sub) {
    vector<int> occurrences; // indexes of occurences

    // First occurence
    size_t pos = s.find(sub, 0);

    // The others
    while (pos != string::npos) {
        occurrences.push_back(pos);

        pos = s.find(sub, pos + 1);
    }

    if (occurrences.empty()) {
        occurrences.push_back(-1);
    }

    return occurrences;
}