#include <cstdio>

char a[12][8];
int v[12][8];

int f(int i, int j, char k) {
	if (i < 0 || i >= 12 || j < 0 || j >= 6 || a[i][j] != k || v[i][j]) return 0;
	v[i][j] = 1;
	return f(i, j - 1, k) + f(i, j + 1, k) + f(i - 1, j, k) + f(i + 1, j, k) + 1;
}

void g(int i, int j, char k) {
	if (i < 0 || i >= 12 || j < 0 || j >= 6 || a[i][j] != k) return;
	a[i][j] = '.';
	g(i, j - 1, k);
	g(i, j + 1, k);
	g(i - 1, j, k);
	g(i + 1, j, k);
}

int main() {
	int i, j, k, r;
	for (i = 0; i < 12; i++) scanf("%s", a[i]);
	for (r = 0;; r++) {
		for (i = 0; i < 12; i++) for (j = 0; j < 6; j++) v[i][j] = 0;
		k = 1;
		for (i = 0; i < 12; i++) for (j = 0; j < 6; j++) if (a[i][j] != '.' && f(i, j, a[i][j]) > 3) {
			k = 0;
			g(i, j, a[i][j]);
		}
		if (k) break;
		for (j = 0; j < 6; j++) {
			for (i = k = 11; k >= 0; k--) if (a[k][j] != '.') a[i--][j] = a[k][j];
			while (i >= 0) a[i--][j] = '.';
		}
	}
	printf("%d\n", r);
	return 0;
}
