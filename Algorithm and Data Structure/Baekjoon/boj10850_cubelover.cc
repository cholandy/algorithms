#include <cstdio>

char a[2002][2002];
char v[2002];

int f(int x) {
	if (v[x]) return 0;
	int i;
	if (a[x][2001]) {
		a[x][2001] = 0;
		return 1;
	}
	v[x] = 1;
	for (i = 0; i < 2000; i++) if (a[x][i] && f(i)) {
		a[x][i] = 0;
		a[i][x] = 1;
		return 1;
	}
	return 0;
}

int main() {
	int i, j, n, m, r = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		a[2000][i] = 1;
		a[i + 1000][2001] = 1;
		scanf("%d", &m);
		while (m--) {
			scanf("%d", &j);
			a[i][j + 1000] = 1;
		}
	}
	while (1) {
		j = 0;
		while (f(2000)) {
			r++;
			j = 1;
			v[2000] = 0;
		}
		if (!j) break;
		for (i = 0; i < 2002; i++) v[i] = 0;
	}
	printf("%d", n - r);
	return 0;
}