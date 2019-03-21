#include <cstdio>
#include <vector>

using namespace std;

int u[10001], v[10001], a[10001], b[10001];
int d[10001][101];

int main()
{
	int tcn;
	scanf("%d", &tcn);
	while (tcn--)
	{
		int i, j, k, l, m, n, t, r = (int)1e9;
		scanf("%d%d%d", &n, &m, &l);
		for (i = 0; i < l; i++) scanf("%d%d%d%d", &u[i], &v[i], &a[i], &b[i]);
		for (i = 0; i <= m; i++) for (j = 2; j <= n; j++) d[i][j] = (int)1e9;
		for (i = 0; i < m; i++) for (j = 0; j < l; j++) if (i + a[j] <= m && d[i + a[j]][v[j]] > d[i][u[j]] + b[j]) d[i + a[j]][v[j]] = d[i][u[j]] + b[j];
		printf(d[m][n] < 1e9 ? "%d\n" : "Poor KCM\n", d[m][n]);
	}
}
