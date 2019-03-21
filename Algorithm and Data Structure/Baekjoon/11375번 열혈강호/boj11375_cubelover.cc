#include <cstdio>

int n, m;
char v[2002];
char a[2002][2002];

void s(int &r)
{
	int t;
	while ((t = getchar()) < 40);
	for (r = t & 15; (t = getchar()) > 40; r = r * 10 + (t & 15));
}

int f(int x)
{
	if (v[x]) return 0;
	int i;
	if (x > n)
	{
		if (a[x][n+m+1])
		{
			a[x][n + m + 1] = 0;
			return 1;
		}
		v[x] = 1;
		for (i = 1; i <= n; i++) if (a[x][i] && f(i))
		{
			a[x][i] = 0;
			a[i][x] = 1;
			return 1;
		}
		return 0;
	}
	v[x] = 1;
	for (i = n + 1; i <= n + m; i++) if (a[x][i] && f(i))
	{
		a[x][i] = 0;
		a[i][x] = 1;
		return 1;
	}
	return 0;
}

int main()
{
	int i, j, l;
	s(n);
	s(m);
	for (i = 1; i <= n; i++)
	{
		a[0][i] = 1;
		s(l);
		while (l--)
		{
			s(j);
			a[i][j + n] = 1;
		}
	}
	for (j = 1; j <= m; j++) a[j + n][n + m + 1] = 1;
	l = 0;
	while (1)
	{
		j = 0;
		for (i = 1; i <= n; i++) if (a[0][i] && f(i))
		{
			j = 1;
			l++;
			a[0][i] = 0;
		}
		if (!j) break;
		for (i = 1; i <= n + m + 1; i++) v[i] = 0;
	}
	printf("%d", l);
}