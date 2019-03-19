#include <cstdio>

int main()
{
	int tcn;
	scanf("%d", &tcn);
	while (tcn--)
	{
		long long a, b;
		int n;
		scanf("%d%lld%lld", &n, &a, &b);
		while (!(a & 1) && !(b & 1))
		{
			n--;
			a >>= 1;
			b >>= 1;
		}
		printf("%d\n", n);
	}
}