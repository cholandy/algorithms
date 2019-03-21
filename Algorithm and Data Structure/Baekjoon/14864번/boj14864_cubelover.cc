#include <cstdio>

int x[1000001], y[1000001];
int d[100001];
int r[100001];

int main() {
	int i, j, n, m;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d%d", &x[i], &y[i]);
		d[y[i]]++;
	}
	for (i = 1; i <= n; i++) {
		for (j = i; d[i]--; j--) r[j] = r[j - 1];
		r[j] = i;
	}
	for (i = 1; i <= n; i++) d[r[i]] = i;
	for (i = 0; i < m; i++) if (d[x[i]] < d[y[i]]) {
		puts("-1");
		return 0;
	}
	for (i = 1; i <= n; i++) printf("%d ", d[i]);
}