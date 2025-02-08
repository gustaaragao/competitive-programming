# STL e C++

*STL (Standard Template Library) é uma biblioteca padrão do C++*
-> EDs, funções e algoritmos já implementados

## Explicando o template

---

```cpp
#include <bits/stdc++.h>
```
É um compilado de muitas bibliotecas do C++. Nos poupa de ficar incluindo diversas coisas

---

```cpp
using namespace std; 
```
O "namespace" é um "sobrenome" de alguma função implementada, usar "std::" ajuda a evitar conflito no uso

Usar o "using namespace std" nos poupa de escrever "std:: sempre (pode gerar conflitos)

---
```cpp
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
```
Definicao de um macro "_" que melhora o I/O. 

Nao podemos ficar usando cout e printf com isso.

---
```cpp
#define f first
#define s second
```

Criacao de macros que sao muito usados.

---
```cpp
#define dbg(x) cout << #x << " = " << x << endl
```

Funcao util de debugging, basta escrever “dbg(a)” que vai printar "a = val a"

---
```cpp
typedef long long ll;
```

Nome alternativo para long long

---

```cpp
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
```

Definicao de valores "infinito" (valores mt grandes), seriam meio que elementos neutros de maximos e minimos.

---

```cpp
int main(){ _
    return 0;
}
```

Note o "_" do *Fast I/O*

---

## Estruturas

### Vector
- Array com funcionalidades novas

- Pode alocar memoria automaticamente

Precisamos definir o tipo do vetor assim: `vector<meu_tipo> v` 

```cpp
vector<int> v;

vector<vector<ll>> v;
```

Podemos definir um vetor com tamanho especifico
```cpp
vector<int> v(n);
```

Podemos inicializar com um valor especifico
```cpp
vector<int> v(n, 1); // Vetor com 1`s
```

`push_back()`: Adicionar um elemento no final. Ja cuida da memoria alocada. *O(1)*

`size()`: retorna o tamanho do objeto. *O(1)*

---

### Pair
- Classe que guarda dois elementos (podem ser de tipos *diferentes*)

- Muitos util para duas informacoes linkadas.

Precisamos definir o tipo do par assim: `pair<tipo1, tipo2> p`
```cpp
pair<int, ll> p;
```

Podemos declarar e inicializar
```cpp
pair<int, ll> p = {0, 1};
```

Podemos acessar com *.first* e *.second* (ou, .f e .s)

## Funcoes

### min e max
Recebe dois ou mais parametros do mesmo *tipo* (podem ser *structs*)

Podemos comparar *pares*: Ele compara o primeiro elemento, se forem iguais ele desempata pelo segundo elemento.

```cpp
int a = max(1, 2); // 2
int b = min(1, 2); // 1

int c = max({1, 2, 3, 4}); // 4
int d = min({1, 2, 3, 4}); // 1
```