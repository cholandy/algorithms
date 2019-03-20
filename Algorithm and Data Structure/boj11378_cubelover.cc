#include <cstdio>

int n, m;
char v[2003];
int a[2003][2003];

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
		if (a[x][n + m + 1])
		{
			a[x][n + m + 1] = 0;
			return 1;
		}
		v[x] = 1;
		for (i = 1; i < n; i++) if (a[x][i] && f(i))
		{
			a[x][i] = 0;
			a[i][x] = 1;
			return 1;
		}
		return 0;
	}
	v[x] = 1;
	if (x == n)
	{
		for (i = 1; i < n; i++) if (a[x][i] && f(i))
		{
			a[x][i]--;
			a[i][x]++;
			return 1;
		}
		return 0;
	}
	if (a[x][n] && f(n))
	{
		a[x][n]--;
		a[n][x]++;
		return 1;
	}
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
	int i, j, l, t;
	s(n);
	s(m);
	s(t);
	n++;
	a[0][n] = t;
	for (i = 1; i < n; i++)
	{
		a[0][i] = 1;
		a[n][i] = m - 1;
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
		for (i = 1; i <= n; i++) while (a[0][i] && f(i))
		{
			j = 1;
			l++;
			a[0][i]--;
		}
		if (!j) break;
		for (i = 1; i <= n + m + 1; i++) v[i] = 0;
	}
	printf("%d", l);
}