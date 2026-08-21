#include <bits/stdc++.h>
using namespace std;

template <class T> struct SegTreeIterative {
  int n;
  vector<T> seg;
  T neutro = 0; // Elemento neutro

  SegTreeIterative(int _n) {
    n = 1;
    while (n < _n)
      n *= 2; // Arredonda para a próxima potência de 2
    seg.assign(2 * n, neutro);
  }

  T combina(T a, T b) { return a + b; }

  // Atualiza a posição p somando val
  void update(int p, T val) {
    p += n;
    seg[p] += val; // Altere para '=' se for substituição
    for (p /= 2; p > 0; p /= 2) {
      seg[p] = combina(seg[2 * p], seg[2 * p + 1]);
    }
  }

  // Consulta no intervalo [l, r]
  T query(int l, int r) {
    T res_esq = neutro, res_dir = neutro;
    for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
      if (l % 2 == 1)
        res_esq = combina(res_esq, seg[l++]);
      if (r % 2 == 1)
        res_dir = combina(seg[--r], res_dir);
    }
    return combina(res_esq, res_dir);
  }
};
