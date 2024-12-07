#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    while (1) {
        int a, b, c, x, y, z;
        scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);

        if (a == 0 && b == 0 && c == 0 && x == 0 && y == 0) break;

        int princesa[3] = { a, b, c };

        qsort(princesa, 3, sizeof(int), compare);
        
        z = -1;
        for (int i = 1; i <= 52; i++) {
            if (i != a && i != b && i != c && i != x && i != y) {
                int principe[3] = { x, y, i };
                
                qsort(principe, 3, sizeof(int), compare);

                int accVitorias = 0;

                if (principe[2] > princesa[0]) accVitorias++;
                if (principe[1] > princesa[2]) accVitorias++;
                if (principe[0] > princesa[1]) accVitorias++;

                if (accVitorias >= 2) {
                    z = i;
                    break;
                }
            }
        }
        printf("%d\n", z);
    }

    return 0;
}
