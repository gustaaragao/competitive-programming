#include <stdio.h>
#include <stdlib.h>

#define MAX_T 101
#define MAX_P 1000

int compara(const void *a, const void *b) {
    return *(int *) b - * (int *) a;
}

int main()
{
    int q, n, best_p;
    
    int alimentos[MAX_T][MAX_P];
    int accAlimentos[MAX_T];


    scanf("%d", &q);

    while (q--) {
        scanf("%d", &n);

        for (int i = 0; i < MAX_T; i++) {
           accAlimentos[i] = 0;
        }

        while(n--) {
            int t, p;
            scanf("%d %d", &t, &p);

            alimentos[t][accAlimentos[t]++] = p;
        }

        int somaP = 0;

        for (int i = 1; i < MAX_T; i++) {
            if (accAlimentos[i] > 0) {
                // Ordem decrescente dos alimentos
                qsort(alimentos[i], accAlimentos[i], sizeof(int), compara);

                best_p = 0;

                for (int j = 0; j < accAlimentos[i]; j++) {
                    if (alimentos[i][j] >= 10 && alimentos[i][j] <= 100) {
                        best_p = alimentos[i][j];
                        break;
                    }
                }

                if (best_p == 0) {
                    best_p = alimentos[i][0];
                }

                somaP += best_p;
            }
        }

        printf("%d\n", somaP);
    }

    return 0;
}