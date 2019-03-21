#include <cstdio>

int a[10000];

int main() {
	unsigned int L, R, M;
	int i, j, n, m;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	L = 0;
	R = 2147483647;
	while (L < R) {
		M = L + R + 1 >> 1;
		j = 0;
		for (i = 0; i < n; i++) j += a[i] / M;
		if (j >= m) L = M;
		else R = M - 1;
	}
	printf("%d", L);
}
