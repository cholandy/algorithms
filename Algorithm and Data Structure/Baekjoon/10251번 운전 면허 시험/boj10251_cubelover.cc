#include <cstdio>
#include <algorithm>

using namespace std;

int a[101][101], b[101][101];
int c[101][101][101], d[101][101][101];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int i, j, k, l, m, n, o, p;
		scanf("%d%d%d%d", &n, &m, &o, &p);
		for (i = 0; i < n; i++) for (j = 1; j < m; j++) scanf("%d", &a[i][j]);
		for (i = 1; i < n; i++) for (j = 0; j < m; j++) scanf("%d", &b[i][j]);
		for (k = 0; k < n + m; k++)
		{
			for (i = 0; i < n; i++) for (j = 0; j < m; j++)
			{
				c[i][j][k] = d[i][j][k] = 1e9;
				if (!i && !j) c[i][j][k] = d[i][j][k] = 0;
				if (i)
				{
					c[i][j][k] = min(c[i][j][k], c[i - 1][j][k] + b[i][j]);
					if (k) c[i][j][k] = min(c[i][j][k], d[i - 1][j][k - 1] + b[i][j]);
				}
				if (j)
				{
					d[i][j][k] = min(d[i][j][k], d[i][j - 1][k] + a[i][j]);
					if (k) d[i][j][k] = min(d[i][j][k], c[i][j - 1][k - 1] + a[i][j]);
				}
			}
			if (c[n - 1][m - 1][k] <= p || d[n - 1][m - 1][k] <= p) break;
		}
		printf("%d\n", k < n + m ? k + (n + m - 2)*o : -1);
	}
}