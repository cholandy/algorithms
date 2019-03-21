#include <cstdio>

inline void assert(bool f) {
	while (!f);
}

int a[22];
int d[11][40004];

int main() {
	int i, j, k, n, t, s = 0;
	assert(scanf("%d", &n) == 1);
	assert(4 <= n && n <= 20 && n % 2 == 0);
	d[0][0] = 1;
	for (i = 0; i < n; i++) for (j = 0; j < n; j++) {
		assert(scanf("%d", &k) == 1);
		assert((i == j && k == 0) || (i != j && 1 <= k && k <= 100));
		a[i] += k;
		a[j] += k;
	}
	for (i = 0; i < n; i++) {
		s += a[i];
		for (j = i < (n >> 1) - 1 ? i : (n >> 1) - 1; j >= 0; j--) for (k = (40000 < s ? 40000 : s) - a[i]; k >= 0; k--) if (d[j][k]) d[j + 1][k + a[i]] = 1;
	}
	s >>= 1;
	for (i = s; !d[n >> 1][i]; i--);
	printf("%d\n", s - i);
	return 0;
}
