#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ENTRADA 0
#define SAIDA 1

typedef struct Evento {
    int tempo, tipo, id;
    Evento(int _tempo, int _tipo, int _id) : tempo(_tempo), tipo(_tipo), id(_id) {}
    // O elemento id é util quando temos que responder queries
    bool operator < (Evento outro) {
        if(tempo == outro.tempo) return tipo < outro.tempo; // Definir o criterio de desempate
        return tempo < outro.tempo;
    }
} evento_t;

int main() { _
    int n; cin >> n;
    vector<evento_t> ev;
    // Leitura dos eventos
    for (int i = 0; i < n; i++) {
        int e, s; cin >> e >> s;
        ev.push_back({e, ENTRADA, i}); // Evento de Entrada
        ev.push_back({s, SAIDA, i});   // Evento de Saida
    }
    // Pre-ordenacao para Varredura
    sort(ev.begin(), ev.end());
    // Varredura --> Verificar qual o maximo de pessoas
    int acc = 0, ans = -1;
    for (auto [tempo, tipo, id] : ev) {
        if (tipo == ENTRADA) acc++;
        else acc--;
        ans = max(ans, acc);
    }
    cout << ans << endl;
    return 0;
}

/*
Problemas de line-sweep sao descritas por duas variaveis:
- Localizacao temporal ou espacial;
- Tipo do evento

O problema está em saber qual a melhor estrutura para armazenar a resposta (um inteiro, um set, uma Segment Tree, ...)

https://noic.com.br/materiais-informatica/curso/line-sweep/
*/