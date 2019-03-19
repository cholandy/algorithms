#include <cstdio>
#include <algorithm>

int f(int a, int b) { return a ? f(b%a, a) : b; }

int main()
{
	int i, n, m, r = 360;
	scanf("%d%d", &n, &m);
	while (n--)
	{
		scanf("%d", &i);
		r = f(r, i);
	}
	while (m--)
	{
		scanf("%d", &i);
		puts(i%r ? "NO" : "YES");
	}
}