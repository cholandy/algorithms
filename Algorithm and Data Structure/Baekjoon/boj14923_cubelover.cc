#pragma GCC optimize("Ofast")
#include <cstdio>
#include <cassert>
#include <queue>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>

using namespace std;

char *p;

inline int readInt() {
	int t, r;
	for (r = *p++ - 48; (t = *p++ - 48) >= 0; r = r * 10 + t);
	return r;
}

int n, m;
int d[2][1001][1001];
queue<int> q;

inline void push(int (*d)[1001], int i, int j, int k) {
	if (i >= 0 && i < n && j >= 0 && j < m && !d[i][j]) {
		d[i][j] = k;
		q.push(i << 16 | j);
	}
}

inline void bfs(int (*d)[1001], int sx, int sy) {
	push(d, sx, sy, 1);
	while (!q.empty()) {
		int i = q.front() >> 16, j = q.front() & 65535;
		q.pop();
		assert(p[i * m + j << 1] == 48 || p[i * m + j << 1] == 49);
		if (p[i * m + j << 1] == 49) continue;
		push(d, i + 1, j, d[i][j] + 1);
		push(d, i - 1, j, d[i][j] + 1);
		push(d, i, j + 1, d[i][j] + 1);
		push(d, i, j - 1, d[i][j] + 1);
	}
}

int main() {
	struct stat buf;
	fstat(0, &buf);
	p = (char *)mmap(0, buf.st_size, PROT_READ, MAP_SHARED, 0, 0);

	int sx, sy, ex, ey;
	n = readInt(); m = readInt();
	sx = readInt(); sy = readInt();
	ex = readInt(); ey = readInt();
	bfs(d[0], sx - 1, sy - 1);
	bfs(d[1], ex - 1, ey - 1);

	int r = 1e9;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (d[0][i][j] && d[1][i][j] && d[0][i][j] + d[1][i][j] < r) r = d[0][i][j] + d[1][i][j];
	printf("%d\n", r > 1e8 ? -1 : r - 2);
	return 0;
}
