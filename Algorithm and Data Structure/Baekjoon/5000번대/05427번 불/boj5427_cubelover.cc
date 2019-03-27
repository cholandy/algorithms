#include <cstdio>

char a[1001][1001];
int b[1001][1001];
int d[1001][1001];

int q[1000001], qn;

int px[4] = { 1,-1,0,0 };
int py[4] = { 0,0,1,-1 };

int main()
{
	int tcn;
	scanf("%d", &tcn);
	while (tcn--)
	{
		int i, j, k, l, m, n, r = 1e9;
		scanf("%d%d", &m, &n);
		qn = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%s", a[i]);
			for (j = 0; j < m; j++)
			{
				b[i][j] = 0;
				if (a[i][j] == '*')
				{
					b[i][j] = 1;
					q[qn++] = i * 10000 + j;
				}
			}
		}
		for (i = 0; i < qn; i++) for (j = 0; j < 4;j++)
		{
			int x = q[i] / 10000 + px[j];
			int y = q[i] % 10000 + py[j];
			if (x >= 0 && x < n && y >= 0 && y < m && !b[x][y] && a[x][y] != '#')
			{
				b[x][y] = b[q[i] / 10000][q[i] % 10000] + 1;
				q[qn++] = x * 10000 + y;
			}
		}
		qn = 0;
		for (i = 0; i < n; i++) for (j = 0; j < m; j++)
		{
			d[i][j] = 0;
			if (a[i][j] == '@')
			{
				d[i][j] = 1;
				q[qn++] = i * 10000 + j;
			}
		}
		for (i = 0; i < qn; i++) for (j = 0; j < 4; j++)
		{
			int x = q[i] / 10000 + px[j];
			int y = q[i] % 10000 + py[j];
			if (x >= 0 && x < n && y >= 0 && y < m && !d[x][y] && (!b[x][y] || d[q[i] / 10000][q[i] % 10000] + 1 < b[x][y]) && a[x][y] != '#')
			{
				d[x][y] = d[q[i] / 10000][q[i] % 10000] + 1;
				q[qn++] = x * 10000 + y;
			}
		}
		for (i = 0; i < n; i++) for (j = 0; j < m; j++) if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && d[i][j] && r > d[i][j]) r = d[i][j];
		printf(r < 1e9 ? "%d\n" : "IMPOSSIBLE\n", r);
	}
}