#include <cstdio>

char a[101][101];

int main() {
	int i, j, k, l, n, tt, f;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d%d%d", &i, &j, &k, &l);
		int pi = (k == 0) - (k == 2), pj = (k == 3) - (k == 1);
		a[i][j] = 1;
		i += pi;
		j += pj;
		a[i][j] = 1;
		for (int t = 1; t < 1 << l; t++) {
			for (k = (t & -t) << 1, f = 1; k <= t; k <<= 1) if (!(t & k) != !(t & k << 1)) f = !f;
			if (f) {
				tt = pi;
				pi = pj;
				pj = -tt;
			}
			else {
				tt = pi;
				pi = -pj;
				pj = tt;
			}
			i += pi;
			j += pj;
			a[i][j] = 1;
		}
	}
	f = 0;
	for (i = 0; i < 100; i++) for (j = 0; j < 100; j++) if (a[i][j] && a[i][j + 1] && a[i + 1][j] && a[i + 1][j + 1]) f++;
	printf("%d\n", f);
	return 0;
}
