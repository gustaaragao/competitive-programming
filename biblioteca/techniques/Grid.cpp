#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ff first
#define ss second
typedef pair<int, int> pi;
const int MAX = 1e3;
int n, m;
char grid[MAX][MAX];
bool vis[MAX][MAX];
// Movimentos: cima, baixo, esquerda, direita
pi mov[16] = {
    // Esquerda, Direita, Cima, Baixo
    {-1, 0}, {1, 0}, {0, -1}, {0, 1},
    // Diagonais
    {-1, -1}, {1, 1}, {-1, 1}, {1, -1},  
    // Movimento de cavalo
    {-2, -1}, {2, 1}, {-2, 1}, {2, -1},   
    {-1, -2}, {1, 2}, {-1, 2}, {1, -2}
};
// Função para validar de new_i, new_j são válidos
bool valid(int i, int j) {
    // Podemos adicionar outras CONDIÇÕES...
    // Por exemplo, "Já foi visitado", "movimento não é obstruído"
    return i >= 0 and j >= 0 and i < n and j < m and !vis[i][j];
}
signed main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int i = 0, j = 0; // Posicao Inicial
    for (auto [di, dj] : mov) {
        int ni = i + di, nj = j + dj;
        if (valid(ni, nj)) {
            vis[ni][nj] = true;
            // Faça algo!
        }
    }
}