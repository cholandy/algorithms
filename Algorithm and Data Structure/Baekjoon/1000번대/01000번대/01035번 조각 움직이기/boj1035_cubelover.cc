#include <cstdio>

char a[5][6];
int c[5], d[5], p[5], n, r = 99;

int e(int x)
{
	return x == p[x] ? x : p[x] = e(p[x]);
}

int f(int x, int y)
{
	return x > y ? x - y : y - x;
}

int g(int x, int y)
{
	return f(x / 5, y / 5) + f(x % 5, y % 5);
}

void h(int m)
{
	if (n == m)
	{
		int i, j;
		for (i = 0; i < n; i++) p[i] = i;
		for (i = 0; i < n; i++) for (j = 0; j < i; j++)
		{
			if (d[i] == d[j]) return;
			if (g(d[i], d[j]) == 1) p[e(i)] = e(j);
		}
		for (i = 1; i < n; i++) if (e(0) != e(i)) return;
		for (i = j = 0; i < n; i++) j += g(c[i], d[i]);
		if (j < r) r = j;
		return;
	}
	for (d[m] = 0; d[m] < 25; d[m]++) h(m + 1);
}

int main()
{
	int i, j;
	for (i = 0; i < 5; i++)
	{
		scanf("%s", a[i]);
		for (j = 0; j < 5; j++) if (a[i][j] == '*') c[n++] = i * 5 + j;
	}
	h(0);
	printf("%d", r);
}