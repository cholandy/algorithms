#include <cstdio>

int d[100001];

int main() {
	int i, j, k, l, m, n, t;
	scanf("%d%d", &n, &m);
	while (n--) {
		scanf("%d%d%d%d", &i, &j, &k, &l);
		for (t = m; t >= 0; t--) {
			d[t] = -1e9;
			if (t >= i && d[t] < d[t - i] + j) d[t] = d[t - i] + j;
			if (t >= k && d[t] < d[t - k] + l) d[t] = d[t - k] + l;
		}
	}
	printf("%d\n", d[m]);
}