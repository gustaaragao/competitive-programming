#include <stdio.h>
#include <string.h>

int main() {
    while (1) {
        int n, m;
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0)
            break;

        char linha[n][m + 1];
        
        for (int i = 0; i < n; i++) {
            scanf("%s", linha[i]);
        }

        int a, b;
        scanf("%d %d", &a, &b);

        int fatorX = a / n;
        int fatorY = b / m;

        for (int i = 0; i < n; i++) {
            char linhaExpandida[b + 1];
            int idx = 0;

            for (int j = 0; j < m; j++) {
                for (int k = 0; k < fatorY; k++) {
                    linhaExpandida[idx++] = linha[i][j];
                }
            }
            
            linhaExpandida[idx] = '\0';

            for (int l = 0; l < fatorX; l++) {
                printf("%s\n", linhaExpandida);
            }
        }

        printf("\n");
    }

    return 0;
}