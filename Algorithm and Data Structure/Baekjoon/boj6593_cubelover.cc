#include <cstdio>

int n, m, l;
char s[32][32][32];
int d[32][32][32];
int q[32768], qn;

void add(int i, int j, int k, int x) {
	if (i < 0 || i >= n || j < 0 || j >= m || k < 0 || k >= l || s[i][j][k] == '#' || d[i][j][k]) return;
	d[i][j][k] = x;
	q[qn++] = i << 10 | j << 5 | k;
}

int main() {
	while (1) {
		int i, j, k, t;
		scanf("%d%d%d", &n, &m, &l);
		if (!n && !m && !l) break;
		qn = 0;
		for (i = 0; i < n; i++) for (j = 0; j < m; j++) {
			scanf("%s", s[i][j]);
			for (k = 0; k < l; k++) {
				d[i][j][k] = 0;
				if (s[i][j][k] == 'S') add(i, j, k, 1);
			}
		}
		for (t = 0; t < qn; t++) {
			i = q[t] >> 10;
			j = q[t] >> 5 & 31;
			k = q[t] & 31;
			add(i - 1, j, k, d[i][j][k] + 1);
			add(i + 1, j, k, d[i][j][k] + 1);
			add(i, j - 1, k, d[i][j][k] + 1);
			add(i, j + 1, k, d[i][j][k] + 1);
			add(i, j, k - 1, d[i][j][k] + 1);
			add(i, j, k + 1, d[i][j][k] + 1);
		}
		for (i = 0; i < n; i++) for (j = 0; j < m; j++) for (k = 0; k < l; k++) if (s[i][j][k] == 'E') printf(d[i][j][k] ? "Escaped in %d minute(s).\n" : "Trapped!\n", d[i][j][k] - 1);
	}
}