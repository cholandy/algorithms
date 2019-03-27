#include <cstdio>
#include <algorithm>

using namespace std;

char a[55][55];
int d[55][55], n, m;

int f(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m || a[x][y] == 'H') return 0;
	if (d[x][y]) return d[x][y];
	d[x][y] = 1e9;
	return d[x][y] = max(max(f(x - (a[x][y] & 15), y), f(x + (a[x][y] & 15), y)), max(f(x, y - (a[x][y] & 15)), f(x, y + (a[x][y] & 15)))) + 1;
}

int main() {
	int i;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) scanf("%s", a[i]);
	i = f(0, 0);
	printf("%d", i > 8e8 ? -1 : i);
}