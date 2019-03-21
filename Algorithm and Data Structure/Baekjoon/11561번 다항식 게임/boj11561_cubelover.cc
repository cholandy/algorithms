#include <cstdio>
#include <cmath>

int main()
{
	int tcn;
	scanf("%d", &tcn);
	while (tcn--)
	{
		long long n, m;
		scanf("%lld", &n);
		m = sqrt(n+n)+1.5;
		while (m*-~m > n + n) m--;
		printf("%lld\n", m);
	}
}