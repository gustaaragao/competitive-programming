# -*- coding: utf-8 -*-

def is_tipico(porcao, porcoes_entrada, tipicos, memoization):
    if porcao in memoization:
        return memoization[porcao]

    componentes = porcoes_entrada.get(porcao, [])
    
    
    acc_tipicos = 0
    for componente in componentes:
        if componente in tipicos:
            acc_tipicos += 1
        elif componente in porcoes_entrada:
            if is_tipico(componente, porcoes_entrada, tipicos, memoization):
                acc_tipicos += 1

    resultado = acc_tipicos > (len(componentes) // 2)
    memoization[porcao] = resultado
    return resultado

def main():
    n = int(input().strip())
    tipicos = input().split()[:n]

    m = int(input().strip())

    porcoes_entrada = {}

    # Lendo as porções
    for _ in range(m):
        entrada = input().strip().split()

        porcao = entrada[0]
        
        numero_componentes = int(entrada[1])

        componentes = input().split()[:numero_componentes]

        porcoes_entrada[porcao] = componentes

    memoization = {}
    for porcao in porcoes_entrada:
        if is_tipico(porcao, porcoes_entrada, tipicos, memoization):
            print("porcao tipica")
        else:
            print("porcao comum")

if __name__ == '__main__':
    main()