#include <cstdio>

unsigned int a[3003], c[1000001];
unsigned int d[3003][3003];

int main()
{
	unsigned int r = 0;
	int i, j, n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%u", a + i);
		c[a[i]] = i;
		for (j = 1; j < i; j++)
		{
			if (a[j] + a[j] > a[i] && c[a[j] + a[j] - a[i]])
			{
				d[j][i] = d[c[a[j] + a[j] - a[i]]][j] + a[j];
				if (r < d[j][i] + a[i]) r = d[j][i] + a[i];
			}
			else d[j][i] = a[j];
		}
	}
	printf("%u", r);
}