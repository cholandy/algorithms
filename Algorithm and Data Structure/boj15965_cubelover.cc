#pragma GCC optimize("Ofast")
#include <cstdio>

unsigned a[230275];

int main() {
	int i, j, n;
	scanf("%d", &n);
	if (!--n) {
		puts("2");
		return 0;
	}
	for (i = 3;; i += 2) if (!(a[i >> 6] >> (i >> 1 & 31) & 1)) {
		if (!--n) break;
		if (i < 2715) for (j = i * i; j < 7368800; j += i << 1) a[j >> 6] |= 1u << (j >> 1 & 31);
	}
	printf("%d\n", i);
	return 0;
}