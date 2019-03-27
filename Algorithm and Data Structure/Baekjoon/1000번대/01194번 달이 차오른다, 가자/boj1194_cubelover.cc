#include <cstdio>

const int INF = 987654321;

int n, m;
char a[64][64];
int d[64][64][64];
int q[262144], qn;

void add(int i, int j, int k, int l) {
	if (i < 0 || i >= n || j < 0 || j >= m || a[i][j] == '#' || a[i][j] >= 'A' && a[i][j] <= 'F' && !(k >> a[i][j] - 'A' & 1)) return;
	if (a[i][j] >= 'a' && a[i][j] <= 'f') k |= 1 << a[i][j] - 'a';
	if (d[i][j][k]) return;
	d[i][j][k] = l;
	q[qn++] = i << 12 | j << 6 | k;
}

int main() {
	int i, j, k, t;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%s", a[i]);
		for (j = 0; j < m; j++) if (a[i][j] == '0') add(i, j, 0, 1);
	}
	for (t = 0; t < qn; t++) {
		i = q[t] >> 12;
		j = q[t] >> 6 & 63;
		k = q[t] & 63;
		add(i + 1, j, k, d[i][j][k] + 1);
		add(i - 1, j, k, d[i][j][k] + 1);
		add(i, j + 1, k, d[i][j][k] + 1);
		add(i, j - 1, k, d[i][j][k] + 1);
	}
	t = INF;
	for (i = 0; i < n; i++) for (j = 0; j < m; j++) if (a[i][j] == '1') for (k = 0; k < 64; k++) if (d[i][j][k] && d[i][j][k] < t) t = d[i][j][k];
	printf("%d", t == INF ? -1 : t - 1);
}