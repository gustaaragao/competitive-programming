# Teoria dos Grafos (Resumo)

Segue o resumo de algumas definições importantes para Grafo :)

## Definição

G(V, E) -> V: Conjunto de vértices e E: Conjunto de Arestas

## Caminho

Um caminho P de x0 para xk é um grafo não vazio da forma V = {x0, x1, ..., xk} e E = {{x0,x1}, {x1, x2}, ..., {xk-1, xk}} em que todos os xi são distintos.

O **comprimento de um caminho** é definido como o **número de arestas** em E.

## Ciclo

Sendo P um caminho de x0 para xk de **comprimento >= 2**, um ciclo é definido como P + {xk, x0}, ou seja, adiciona uma aresta fechando o ciclo.

### Ciclo Simples

É um tipo especial de ciclo, onde:
- Nenhum vértice (além do inicial e final) se repete.
- Nenhuma aresta se repete
- E tem ao menos **3 vértices distintos** (em grafos simples) --> **comprimento >= 3**

## Conectividade

Um grafo é dito **conexo** se para todo par de vértices v, w de G **existe um caminho** de v para w em G.

Caso contrário, o grafo é **desconexo**.

### Componente Conexo

Um **subgrafo conexo maximal** de um grafo G é chamado de componente conexo.

## Vizinho e Grau

Para cada vértice, os vértices que podemos atingir a partir das suas arestas são conhecidos como **vizinhos**.

O número de vizinhos de um vértice é chamado de **grau**.

## Árvore

**Definição:** Um grafo **acíclico (sem ciclo)** e **conexo**.

- **Folhas:** Vértices de grau 1
- **Raiz:** Uma árvore pode ser enraizada por um vértice qualquer -> Noção de Pai e Filhos

**Afirmações:**

- G é uma árvore <-> G é um grafo conexo e |E| = |V| - 1

- G é uma árvore <-> G possui para todo v, w de G existe EXATAMENTE UM caminho de v para w

- G é uma árvore <-> G é conexo e tirar uma aresta de G o torna acíclico

- G é uma árvore <-> G não contém ciclos, mas adicionar qualquer aresta à G cria um ciclo

## Diâmetro

Consiste no **maior caminho de uma árvore**.