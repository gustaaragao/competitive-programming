#include <bits/stdc++.h>
using namespace std; 

#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pi;

const ll MOD = 1e9 + 7;

signed main(){
    FAST_IO

    int n, c; cin >> n >> c;
    vector<string> palavras(n);
    for (auto &p : palavras) cin >> p;

    map<string ,int> mp;
    for (int i = 0; i < n; i++) {
        int pos_asterisco = -1;
        // Encontrar a posição do asterisco
        for (int j = 0; j < n; j++) {
            if (palavras[i][j] == '*') {
                pos_asterisco = j;
                break;
            }
        }
        // Percorrer por todas as possibilidades do asterisco
        // Como 1 <= C (tamanho da string) <= 12 é pequeno
        // Podemos brutar todas as possibilidades e contar a frequência em um map
        for (char c = 'a'; c <= 'z'; c++) {
            palavras[i][pos_asterisco] = c;
            mp[palavras[i]]++;
        }
    }

    // A solução consiste na string com a maior contagem dentro do map
    string ans_string;
    int ans_count = -1;
    for (auto [p, count] : mp) {
        if (count > ans_count) {
            ans_string = p;
            ans_count = count;
        }
    }
    cout << ans_string << " " << ans_count << endl;
}