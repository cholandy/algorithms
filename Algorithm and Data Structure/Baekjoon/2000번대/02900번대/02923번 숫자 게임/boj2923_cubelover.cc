#include <cstdio>

int a[101], b[101], c[101], d[101];

int main() {
	int i, j, n, u, v, r;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &u, &v);
		a[u]++;
		b[v]++;
		for (i = 1; i <= 100; i++) {
			c[i] = a[i];
			d[i] = b[i];
		}
		i = 1; j = 100;
		r = 0;
		while (j) {
			if (!d[j]) {
				j--;
				continue;
			}
			if (i + j > r) r = i + j;
			if (c[i] < d[j]) {
				d[j] -= c[i];
				c[i] = 0;
				i++;
			}
			else {
				c[i] -= d[j];
				d[j] = 0;
			}
		}
		printf("%d\n", r);
	}
}