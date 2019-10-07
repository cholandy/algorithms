#include <cstdio>

int a[10001];
int d[10001];
int q[10001], qn;

void add(int x, int y) {
	if (d[x]) return;
	d[x] = y;
	q[qn++] = x;
}

int main() {
	int i, j, n, s, e;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	scanf("%d%d", &s, &e);
	add(s - 1, 1);
	for (i = 0; i < qn; i++) {
		for (j = q[i] - a[q[i]]; j >= 0; j -= a[q[i]]) add(j, d[q[i]] + 1);
		for (j = q[i] + a[q[i]]; j < n; j += a[q[i]]) add(j, d[q[i]] + 1);
	}
	printf("%d", d[e - 1] - 1);
}
