#include <cstdio>

int d[32];

int main() {
	int i, j, k, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d%d", &j, &k);
		if (d[i] < d[i - 1]) d[i] = d[i - 1];
		if (d[i + j] < d[i] + k) d[i + j] = d[i] + k;
	}
	if (d[n] < d[n - 1]) d[n] = d[n - 1];
	printf("%d", d[n]);
}
