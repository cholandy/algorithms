#include <cstdio>

int a[10];
double b[10];

int main() {
	double t, p, r = 0.0;
	int i, j, n, m, l;
	scanf("%d%d%d", &n, &m, &l);
	for (i = 0; i < n; i++) scanf("%d%lf", &a[i], &b[i]);
	for (i = 0; i < 1 << n; i++) {
		t = p = 100.0;
		for (j = 0; j < n; j++) {
			if (i >> j & 1) {
				p *= a[j] / 100.;
				if (t - l > 1e-9) t *= 1 + (b[j] - 1) * m / 100.;
			}
			else {
				p *= (100 - a[j]) / 100.;
				if (t - l > 1e-9) t *= 1 - m / 100.;
			}
		}
		if (t > 100) r += p;
	}
	printf("%.2f", r);
}