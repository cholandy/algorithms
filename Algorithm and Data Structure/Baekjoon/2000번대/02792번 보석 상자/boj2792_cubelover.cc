#include<cstdio>

int a[300000];

int main()
{
	long long n, t;
	int i, m, s, e, x;
	scanf("%lld%d", &n, &m);
	for (i = 0; i < m; i++) scanf("%d", &a[i]);
	s = 0;
	e = 1e9;
	while (s < e)
	{
		x = s + e >> 1;
		t = 0;
		for (i = 0; i < m; i++) t += (a[i] + x - 1) / x;
		if (t > n) s = x + 1;
		else e = x;
	}
	printf("%d", s);
}