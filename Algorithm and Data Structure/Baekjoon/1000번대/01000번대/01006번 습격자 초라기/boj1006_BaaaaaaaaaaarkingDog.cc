#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;

int a[10001];
int b[10001];
int d[10001][4];

void f()
{
	int i;
	for (i = 2; i <= n; i++)
	{
		d[i][1] = d[i][2] = d[i - 1][3] + 1;
		if (a[i] + a[i - 1] <= m && d[i][1] > d[i - 1][2] + 1) d[i][1] = d[i - 1][2] + 1;
		if (b[i] + b[i - 1] <= m && d[i][2] > d[i - 1][1] + 1) d[i][2] = d[i - 1][1] + 1;
		d[i][3] = min(d[i][1], d[i][2]) + 1;
		if (a[i] + b[i] <= m && d[i][3] > d[i - 1][3] + 1) d[i][3] = d[i - 1][3] + 1;
		if (a[i] + a[i - 1] <= m && b[i] + b[i - 1] <= m && d[i][3] > d[i - 2][3] + 2) d[i][3] = d[i - 2][3] + 2;
	}
}

int main()
{
	int tcn;
	scanf("%d", &tcn);
	while (tcn--)
	{
		int i, r;
		scanf("%d%d", &n, &m);
		for (i = 1; i <= n; i++) scanf("%d", a + i);
		for (i = 1; i <= n; i++) scanf("%d", b + i);
		if (n == 1)
		{
			puts(a[1] + b[1] <= m ? "1" : "2");
			continue;
		}
		d[0][1] = d[0][2] = d[0][3] = 0;
		d[1][1] = d[1][2] = 1;
		d[1][3] = a[1] + b[1] <= m ? 1 : 2;
		f();
		r = d[n][3];
		d[0][3] = 1e9;
		d[1][3] = 2;
		if (a[1] + a[n] <= m)
		{
			d[1][1] = 1;
			d[1][2] = 2;
			f();
			r = min(r, d[n][2]);
		}
		if (b[1] + b[n] <= m)
		{
			d[1][1] = 2;
			d[1][2] = 1;
			f();
			r = min(r, d[n][1]);
		}
		if (a[1] + a[n] <= m && b[1] + b[n] <= m)
		{
			d[1][1] = d[1][2] = 1e9;
			d[1][3] = 2;
			f();
			r = min(r, d[n - 1][3]);
		}
		printf("%d\n", r);
	}
}