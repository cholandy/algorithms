#include <cstdio>

char a[100001];
char c[100001];
int d[100001];

char t[4];

int main()
{
	int i, j, k, l, m, n;
	while (~scanf("%d%d", &n, &m))
	{
		for (i = 1; i <= n; i++) c[i] = d[i] = 0;
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &j);
			a[i] = j;
			if (a[i] < 0) for (j = i; j <= n; j += j&-j) c[j] ^= 1;
			if (!a[i]) for (j = i; j <= n; j += j&-j) d[j]++;
		}
		while (m--)
		{
			scanf("%s%d%d", t, &i, &j);
			if (t[0] == 'C')
			{
				if (a[i] < 0) for (k = i; k <= n; k += k&-k) c[k] ^= 1;
				if (!a[i]) for (k = i; k <= n; k += k&-k) d[k]--;
				a[i] = j;
				if (a[i] < 0) for (k = i; k <= n; k += k&-k) c[k] ^= 1;
				if (!a[i]) for (k = i; k <= n; k += k&-k) d[k]++;
			}
			else
			{
				k = 0;
				for (l = j; l; l -= l&-l) k += d[l];
				for (l = i - 1; l; l -= l&-l) k -= d[l];
				if (k)
				{
					putchar(48);
					continue;
				}
				for (k = 0; j; j -= j&-j) k ^= c[j];
				for (i--; i; i -= i&-i) k ^= c[i];
				putchar(k ? 45 : 43);
			}
		}
		putchar(10);
	}
}