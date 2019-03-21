#pragma GCC optimize("O3")
#pragma GCC target("arch=skylake")
#include <cstdio>
#include <cmath>

double x[16], y[16], a[16][16];

int main() {
	float d[65536][16];
	int i, j, k, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%lf%lf", &x[i], &y[i]);
		for (j = 0; j < i; j++) a[i][j] = a[j][i] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
	}
	for (i = 0; i < 1 << n; i++) for (j = 0; j < n; j++) d[i][j] = 1e9;
	for (i = 1; i < n; i++) d[1 << i][i] = a[0][i];
	for (i = 1; i < 1 << n; i++) for (j = 0; j < n; j++) if (i >> j & 1) for (k = 0; k < n; k++) if (!(i >> k & 1)) {
		double t = d[i][j] + a[j][k];
		if (d[i | 1 << k][k] > t) d[i | 1 << k][k] = t;
	}
	printf("%.12f\n", d[(1 << n) - 1][0]);
	return 0;
}
