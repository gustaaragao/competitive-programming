#include <stdio.h>

unsigned long long int power(int a, int b) {
    if (b == 0) return 1;
    return a * power(a, b - 1);
}

int main()
{
    int n;

    scanf("%d", &n);

    printf("%llu\n", power(3, n));

    return 0;
}