#include <cstdio>

int a[22][22];

int main()
{
	int i, j, k, n, t, r = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) for (j = 0; j < n; j++) scanf("%d", &a[i][j]);
	for (i = 0; i < n; i++) for (j = 0; j < i; j++)
	{
		t = 1;
		for (k = 0; k < n; k++) if (i != k && j != k)
		{
			if (a[i][j] > a[i][k] + a[k][j])
			{
				puts("-1");
				return 0;
			}
			else if (a[i][j] == a[i][k] + a[k][j]) t = 0;
		}
		if (t) r += a[i][j];
	}
	printf("%d", r);
}