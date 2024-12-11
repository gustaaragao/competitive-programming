#include <stdio.h>
#include <string.h>

unsigned long long int fatK(int n, int k) {
	int i = 1;

	unsigned long long result = n;

	while (1) {
		if (n - i*k < 1) break;

		result *= (n - i*k);

		i++;
	}

	return result;
}

int main() {
	int t, n;
	char k[20];

	scanf("%d", &t);
	
	for (int i = 0; i < t; i++) {
		scanf("%d%s", &n, k);
		
		printf("%llu\n", fatK(n, strlen(k)));
	}
	
	return 0;
}