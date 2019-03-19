#include<cstdio>

int a[55];
int p[55];

int f(int x)
{
	return x == p[x] ? x : p[x] = f(p[x]);
}

int main()
{
	int i, j, n, m, l;
	scanf("%d%d", &n, &m);
	m++;
	for (i = 1; i <= m; i++)
	{
		p[i] = i;
		scanf("%d", &l);
		while (l--)
		{
			scanf("%d", &j);
			if (a[j]) p[f(i)] = f(a[j]);
			a[j] = i;
		}
	}
	j = 0;
	for (i = 1; i <= m; i++) if (f(i) != f(1)) j++;
	printf("%d", j);
}