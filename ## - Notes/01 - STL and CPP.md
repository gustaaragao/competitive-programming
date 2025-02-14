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

## Strings

Um vetor de caracteres.

```cpp
string str;

string str = "gustavo";
```

Podemos comparar strings O(|str|) com `==`.

*Truques Legais*
- Voce pode trazer os caracteres de uma string para numeros inteiros indexados do 0. Para fazer isso basta subtrarir 'a'.

```cpp
string str = "abcde";

for (int i = 0; i < str.size(); i++) str[i] -= 'a';

cout << "Depois: "
for (int i = 0; i < str.size(); i++)
    cout << (int) str[i] << " ";
cout << endl;

/*
Depois: 0 1 2 3 4
*/
```

## Outras estruturas

### Set

Funciona como um *conjunto* da matematica.

- Muito util para eliminar elementos repetidos.

- Uma estrutura ordenada

Declaramos com `set<meu_tipo>`.

```cpp
set<int> s;

s.insert(5); // Inserir: O(log(|s|))

s.erase(5); // Remover: O(log(|s|))

s.count(5); // (Conta quantas vezes o elemento aparece) Verifica se um elemento pertence ao conjunto (retorna 0 ou 1)
```

### Map

Permite usar um tipo qualquer como chave de acesso de algum elemento.

- Uma estrutura ordenada

```cpp
map<string, int> mp;
```

- Para acessar um map usamos `mp[x]` O(log(|mp|)). 

```cpp
map<string,int> mp;
mp["ribossomo"] = 1;
cout << mp["mitocondria"] << " " << mp["ribossomo"] << endl;

// Saida:
// 0 1 (Por padrao ao acessar uma chave nao criada, ele cria uma instancia com o construtor padrao da classe)
```

## Sort

Funcao que ordena os elementos. O(n.logn)

```cpp
// Ordena o vetor todo
sort(v.begin(), v.end());

// Ordena o vetor do inicio ate inicio + n
sort(v.begin(), v.begin() + n);

// Ordena o vetor do maior elemento para o menor
sort(v.begin(), v.end(), greater<>());
```

## Auto

Permite declarar uma variavel sem nomear seu tipo.

- Acontece em tempo de compilacao -> inferencia do tipo

- Nao funciona de forma dinamica como no Python!

- Torna facil de iterar em sets e maps

## Ranged-based for

Um *for* que parece com o python

### Vetor

```cpp
vector<int> v = {0, 1, 2}

for (auto& i : v) i = i + 1; // Faz um for pelas referencias de i (modifica valor)

for (auto i : v) cout << i << " "; // Faz uma copia do i

cout << endl;
```

### Set

```cpp
set<pair<int,char>> s;

s.insert({2, 'a'});
s.insert({1, 'b'});

for (auto p : s) cout << p.f << " " << p.s << endl;

/* Note que ele ordenou os pares
1 b
2 a
*/
```

### Map

```cpp
map<int, char> m;

m[2] = 'b';
m[1] = 'a';

for (auto i : s) cout << i.f << " " << i.s << endl; // o auto seria um pair<chave, valor>


/* Note que ele ordenou os pares
1 a
2 b
```

## Stack e Queue

### Stack (pilha)

- Olhar o elemento mais recente: `.top()`
- Tirar o elemento mais recente: `.pop()`
- Inserir um elemento: `.push()`

### Queue (fila)

- Olhar o elemento colocado a mais tempo: `.front()`
- Tirar o elemento colocado a mais tempo: `.pop()`
- Inserir um elemento: `.push()`
