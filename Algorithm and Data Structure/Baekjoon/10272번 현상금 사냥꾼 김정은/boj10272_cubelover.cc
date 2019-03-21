#include <cstdio>
#include <cmath>

int x[512], y[512];
double d[512][512];

inline double f(int i, int j) {
	return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

int main() {
	int Tn;
	scanf("%d", &Tn);
	while (Tn--) {
		double t, r;
		int i, j, n;
		scanf("%d", &n);
		for (i = 0; i < n; i++) scanf("%d%d", &x[i], &y[i]);
		for (i = 0; i < n; i++) for (j = 0; j < n; j++) d[i][j] = 1e9;
		d[1][0] = f(0, 1);
		for (i = 1; i + 1 < n; i++) for (j = 0; j < i; j++) {
			t = d[i][j] + f(i + 1, j);
			if (t < d[i + 1][i]) d[i + 1][i] = t;
			t = d[i][j] + f(i + 1, i);
			if (t < d[i + 1][j]) d[i + 1][j] = t;
		}
		r = 1e9;
		for (j = 0; j < n - 1; j++) {
			t = d[n - 1][j] + f(n - 1, j);
			if (t < r) r = t;
		}
		printf("%.12f\n", r);
	}
}