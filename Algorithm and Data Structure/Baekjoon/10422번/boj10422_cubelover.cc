#include <cstdio>

const int p = 1000000007;

int d[2501];

int main()
{
	int i, n, t;
	d[0] = 1;
	for (i = 1; i <= 2500; i++) d[i] = d[i - 1] * (i + i - 1LL) * (i + i) % p;
	t = 667749624;
	for (i = 2500; i >= 1; i--)
	{
		d[i] = (long long)d[i] * t%p;
		t = (long long)t*(i + 1) % p;
		d[i] = (long long)d[i] * t%p;
	}
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &i);
		printf("%d\n", i & 1 ? 0 : d[i >> 1]);
	}
}