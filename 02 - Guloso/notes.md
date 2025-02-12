# Guloso

## Exercício Motivador: Fatorial

Dado um inteiro positivo N, você deve escrever um programa para determianr o menor número k tal que = a_1! + a_2! + ... + a_k!, onde cada a_i, para 1 <= i <= k é um número inteiro positivo.

Exemplos:

10 -> 3 (10 = 3! + 2! + 2!)
25 -> 2 (25 = 4! + 1!)

## Definição

Um problema de *otimização* (máximos, mínimos) sobre um conjunto de elementos.

- Você pode *escolher* quais elementos constituirão sua resposta!

- Fazer escolhas *localmente* ótimas de maneira que a combinação gere uma solução *globalmente* ótima.

- Geralmente *N grande* é um indicativo de algoritmo guloso.

### Memorization do fatorial

```cpp
vector<int> fat(11); // 10! > 10**5 (que eh o limite do N no problema)
fat[0] = 1;
for (int i = 1; i <= 10; i++) fat[i] = fat[i - 1] * i;
```

O vetor `fat` tem o fatorial de 0 até 10.

## Pré-ordenação

Geralmente uma ordeção dos elementos de entrada ajuda na solução de alguns problemas gulosos.

- Vetor de *números*: ordenar de forma crescente/decrescente e sempre que possível adicionados os valores na resposta.

- Vetor de *palavaras*: ordenar lexicograficamente.

- Vetor de *pares*: ordenar pela diferença (second-first) -> tamanho do vetor, ordenar pelo primeiro/segundo -> um intervalo, ou por uma fórmula f(x, y).

### Comparador

Função booleana que pode ser passada para o sort(), deve returnar true quando um numero eh *MENOR* que outro.

```cpp
bool cmp(tipo a, tipo b) {
    // ...
}

sort(v.begin(), v.end(), cmp);
```

## Kadane

A melhor soma para a posicao i depende apenas do valor de i e da melhor soma ate i-1.

- Manteremos uma variavel `soma_ant` que eh a maior soma ate a posicao i-1.

- Se soma_ant for maior que 0, a soma maxima de i sera v[i] + soma_ant.
    -> Adicionar um novo elemento pode trazer a possibilidade de melhorar (ou piorar) essa soma

- Se soma_ant for menor que 0, a soma maxima de i sera v[i].
    -> Nao vale a pena continuar com esse subarray, pois caso v[i] seja positivo ou negativo isso apenas vai distanciar da maior soma.

- Atualizamos soma_ant e vemos se eh maior que nossa resposta (max).

Obs.: Inicializar os params com `-INF` (elemento neutro do max).

```cpp
// Kadane
int ans = -INF, soma_ant = -INF;
for (int i = 0; i < n; i++) {
    if (soma_ant > 0) {
        soma_ant = soma_ant + v[i];
    } else {
        soma_ant = v[i];
    }
    ans = max(ans, soma_ant);
}
```