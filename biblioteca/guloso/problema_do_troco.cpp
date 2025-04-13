#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

vector<int> solve(int troco, vector<int> moedas) {
    // Ordenacao decrescente de moedas
    sort(moedas.begin(), moedas.end(), greater<>());
    int troco_atual = troco;
    vector<int> ans;
    for (auto moeda : moedas) {
        while (troco >= moeda) {
            ans.push_back(moeda);
            troco -= moeda;
        }
    }
    return ans;
}

int main() {
    vector<int> moedas = {25, 10, 5, 1};
    vector<int> ans = solve(42, moedas);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}