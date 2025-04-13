#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define f first
#define s second

typedef pair<int, int> ii;

bool cmp(ii a, ii b) {
    if (a.s != b.s) return a.s < b.s; // escolher o que termina antes
    else return a.f < b.f; // desempate para a.s == b.s (terminam juntos) -> pega o que comeca antes
}

int solve(vector<ii> &input) {
    sort(input.begin(), input.end(), cmp); // Ordenar em ordem crescente o horario de saida

    int ans = 0, fim = -1;
    for (auto horario : input) {
        if (horario.f > fim) {
            ans++;
            fim = horario.s;
        }
    }

    return ans;
}

int main() {
    vector<int> inicio = {1, 2, 3, 3, 6};
    vector<int> fim = {3, 5, 9, 5, 8};
    vector<ii> input(5);
    for (int i = 0; i < 5; i++) {
        input[i].f = inicio[i];
        input[i].s = fim[i];
    }

    cout << solve(input) << endl;

    return 0;
}