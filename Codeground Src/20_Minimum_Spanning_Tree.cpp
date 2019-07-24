#include <stdio.h>

#define VMAX 10005
#define EMAX 100005

int uf[VMAX];

struct list {
	int x, y, cost;
}v[EMAX], tmp[EMAX];

int disjoint(int x) {
	return (x != uf[x]) ? uf[x] = disjoint(uf[x]) : x;
}

void MergeSort(int l, int r) {
	if (l == r) return;
	int m = (l + r) / 2;
	
	MergeSort(l, m);
	MergeSort(m + 1, r);

	int x = l, y = m + 1, i = l;

	while (x <= m || y <= r) {
		if (y > r || (x <= m && v[x].cost < v[y].cost)) tmp[i++] = v[x++];
		else tmp[i++] = v[y++];
	}

	for (int i = l; i <= r; i++) v[i] = tmp[i];
}

int main() {
	int n, m;

	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) uf[i] = i;

	for (int i = 0; i < m; i++)
		scanf("%d%d%d", &v[i].x, &v[i].y, &v[i].cost);

	MergeSort(0, m - 1);

	int ans = 0;

	for (int i = 0; i < m; i++)
		if (disjoint(v[i].y) != disjoint(v[i].x)) {
			uf[disjoint(v[i].y)] = uf[v[i].x];
			ans += v[i].cost;
		}

	printf("%d\n", ans);
}