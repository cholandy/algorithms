#include <cstdio>
#include <algorithm>

using namespace std;

int ax[101], ay[101];
int bx[13], by[13];
int d[13];

int main() {
	int an, bn;
	int i, j, k, n, m, s, t, r = 1e9;
	scanf("%d%d", &n, &m);
	an = bn = 0;
	for (i = 0; i < n; i++) for (j = 0; j < n; j++) {
		scanf("%d", &k);
		if (k == 1) {
			ax[an] = i;
			ay[an] = j;
			an++;
		}
		if (k == 2) {
			bx[bn] = i;
			by[bn] = j;
			bn++;
		}
	}
	for (i = 0; i < m; i++) d[i] = 1;
	do {
		s = 0;
		for (i = 0; i < an; i++) {
			t = 1e9;
			for (j = 0; j < bn; j++) if (d[j]) t = min(t, abs(ax[i] - bx[j]) + abs(ay[i] - by[j]));
			s += t;
		}
		if (s < r) r = s;
	} while (prev_permutation(d, d + bn));
	printf("%d\n", r);
	return 0;
}
