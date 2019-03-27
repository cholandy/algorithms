#include <cstdio>

int a[10001];
int b[10001];
int v[10001];
int z;

int c[10001], d[10001];

void f(int x, int y)
{
	if (x < 0) return;
	f(a[x], y + 1);
	z++;
	if (z < c[y]) c[y] = z;
	if (z > d[y]) d[y] = z;
	f(b[x], y + 1);
}

int main()
{
	int i, j, n, t, r;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		c[i] = 1e9;
		d[i] = -1e9;
		scanf("%d", &j);
		scanf("%d%d", a + j, b + j);
		if (a[j] > 0) v[a[j]] = 1;
		if (b[j] > 0) v[b[j]] = 1;
	}
	for (i = 1; i <= n; i++) if (!v[i]) f(i, 1);
	t = r = -1;
	for (i = 1; i <= n; i++) if (d[i] - c[i] > r)
	{
		t = i;
		r = d[i] - c[i];
	}
	printf("%d %d", t, r + 1);
}