(dicas da lib do collares - traduzido)

# Dicas Gerais de Estratégia

* Todos devem ter lido todos os problemas até o final da segunda hora de competição.
* **Na última hora, apenas uma questão deve ser tentada por vez.**
* Sempre use *vectors* em vez de *arrays* no caso unidimensional.
* Use *vectors* em vez de *arrays* no caso bidimensional se a dimensão mais externa (número de linhas) não for muito grande. Isso permite uma melhor depuração (*debugging*).

# Ao Pensar (Antes de Programar)

1. **Seja organizado(a)!**
2. Não toque no computador a menos que a solução esteja pronta, incluindo os detalhes de implementação: evite pensar demais em frente ao computador.
**O tempo gasto no papel detalhando uma solução é tempo bem gasto.**
3. Um corolário do ponto acima:
**Não toque no computador se tiver dúvidas sobre a sua ideia.**

# Caso Você Não Tenha Ideias de Solução

1. (Inclua os truques de Pólya aqui) -> TODO: Gabrielzinho faça essa parte

# Em Caso de *Wrong Answer* (Resposta Errada)

1. Certifique-se de que o algoritmo está correto (ou seja, **esboce uma prova de corretude**) o mais rápido possível. Leve o tempo que precisar e verifique com cuidado.
**Se você tem certeza de que a ideia está correta, não duvide dela** ao procurar por *bugs*, mesmo que não encontre nenhum erro de implementação em lugar nenhum.

2. Se o código usa *vectors*, adicione `#define _GLIBCXX_DEBUG` bem no **início do código-fonte** e submeta novamente. Um erro de execução (*runtime error*) geralmente significa acesso fora dos limites do *array* (*out-of-bounds*) ou outro uso incorreto da STL.

3. Depure no papel e não volte para o computador a cada *bug* que encontrar: **verifique a solução inteira pelo menos mais uma vez após encontrar cada novo *bug***.

4. Pense em casos de teste capciosos (*tricky test cases*).

5. Leia o problema novamente. Para cada restrição encontrada, verifique o código-fonte impresso.

6. Se você não conseguir encontrar nenhum *bug* em cinco minutos, vá ao banheiro.
    6.1. Se ainda assim não conseguir encontrar o *bug*, vá para outro problema e volte para a solução errada mais tarde.
    6.2. Depurar um único programa por muito tempo leva a encontrar muitos falsos *bugs* e faz com que seja fácil deixar passar erros simples.

7. Use o `assert(condição)` para verificar:
    - Se um **algoritmo construtivo** seu bate com as condiçãos que o problema pede.
    - Para testar possíveis cenários de casos de testes. Gaste um WA/RE para verificar se os casos de teste são do jeito que você imagina.  

# Em Caso de *Runtime Error* (Erro de Execução)

1. Verifique possível overflow nas operações.
2. Verifique divisões e operações de módulo.
3. Verifique os índices dos *arrays* (tanto nas declarações quanto nos acessos).
4. Verifique se há recursões infinitas ou *loops* `while` infinitos.