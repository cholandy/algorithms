#include <cstdio>

int d[32000];

int main() {
	int i, n, m;
	while (scanf("%d%d", &n, &m) == 2) {
		int j, k, r;
		for (i = 2; i * i <= m; i++) {
			while (!(m % i)) {
				m /= i;
				d[i]++;
			}
		}
		for (r = n < m ? 1 : m; i > 1; i--) if (d[i]) {
			k = 0;
			for (j = n; (j /= i) && k < d[i]; k += j);
			if (k > d[i]) k = d[i];
			d[i] = 0;
			while (k--) r *= i;
		}
		printf("%d\n", r);
	}
}