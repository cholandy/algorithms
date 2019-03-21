#include <cstdio>

int a[1001];

int main()
{
	int i, n, m, l;
	scanf("%d%d%d", &n, &m, &l);
	for (i = 0; i < n; i++) scanf("%d", a + i);
	if (l <= n && m <= a[l - 1])
	{
		puts("-1");
		return 0;
	}
	for (i = 0; i < n && m < a[i]; i++);
	printf("%d", i + 1);
}