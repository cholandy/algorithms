#include <cstdio>
#include <algorithm>

using namespace std;

char t[4];
int sx[1010], sy[1010], ex[1010], ey[1010], px[1010], py[1010], z[1010];

int main() {
	long long T;
	int L, R;
	int i, j, n, m;
	scanf("%d%d", &n, &m);
	sx[0] = ex[0] = sx[1] = sx[2] = sy[0] = sy[1] = ey[1] = sy[3] = -n - 1;
	ex[1] = ex[2] = sx[3] = ex[3] = ey[0] = sy[2] = ey[2] = ey[3] = n + 1;
	m += 4;
	px[4] = 1;
	T = 0;
	for (i = 4; i < m; i++) {
		scanf("%d%s", &z[i], t);
		ex[i] = sx[i] + px[i] * (z[i] - 1);
		ey[i] = sy[i] + py[i] * (z[i] - 1);
		for (j = 0; j < i; j++) if (max(min(sx[i], ex[i]), sx[j]) <= min(max(sx[i], ex[i]), ex[j]) && max(min(sy[i], ey[i]), sy[j]) <= min(max(sy[i], ey[i]), ey[j])) break;
		if (j == i) {
			sx[i + 1] = sx[i] + px[i] * z[i];
			sy[i + 1] = sy[i] + py[i] * z[i];
			if (sx[i] > ex[i]) swap(sx[i], ex[i]);
			if (sy[i] > ey[i]) swap(sy[i], ey[i]);
			if (t[0] == 'L') {
				px[i + 1] = -py[i];
				py[i + 1] = px[i];
			}
			else {
				px[i + 1] = py[i];
				py[i + 1] = -px[i];
			}
			T += z[i];
			continue;
		}
		L = 0;
		R = z[i] - 1;
		while (L < R) {
			z[i] = L + R >> 1;
			ex[i] = sx[i] + px[i] * z[i];
			ey[i] = sy[i] + py[i] * z[i];
			for (j = 0; j < i; j++) if (max(min(sx[i], ex[i]), sx[j]) <= min(max(sx[i], ex[i]), ex[j]) && max(min(sy[i], ey[i]), sy[j]) <= min(max(sy[i], ey[i]), ey[j])) break;
			if (j == i) L = z[i] + 1;
			else R = z[i];
		}
		printf("%lld\n", T + L);
		return 0;
	}
	L = 0;
	R = 1e9;
	while (L < R) {
		z[i] = L + R >> 1;
		ex[i] = sx[i] + px[i] * z[i];
		ey[i] = sy[i] + py[i] * z[i];
		for (j = 0; j < i; j++) if (max(min(sx[i], ex[i]), sx[j]) <= min(max(sx[i], ex[i]), ex[j]) && max(min(sy[i], ey[i]), sy[j]) <= min(max(sy[i], ey[i]), ey[j])) break;
		if (j == i) L = z[i] + 1;
		else R = z[i];
	}
	printf("%lld\n", T + L);
	return 0;
}
