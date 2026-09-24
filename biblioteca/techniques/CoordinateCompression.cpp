#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define uniq(v) sort(all(v)); v.erase(unique(all(v)), v.end())
// Considere que 1 <= ai <= 10^9 e 1 <= |a| <= 10^5.
// Vamos comprimir os valores de ai para  [0, 10^5-1]. -> 0-INDEXED
void compress(vector<int> &v) {
    vector<int> vals;
    for (auto x : v) vals.pb(x);
    uniq(vals);
    for (auto &x : v) x = lower_bound(all(vals), x) - vals.begin() + 1;
}