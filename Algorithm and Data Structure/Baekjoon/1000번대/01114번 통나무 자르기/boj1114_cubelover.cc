#include <cstdio>
#include <algorithm>

using namespace std;

int a[100001];

int main()
{
	int L, R, M;
	int i, j, k, n, m, l;
	scanf("%d%d%d", &l, &n, &m);
	for (i = 1; i <= n; i++) scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	L = l - a[n];
	for (i = 1; i <= n; i++) L = max(L, a[i] - a[i - 1]);
	R = l;
	while (L < R)
	{
		M = L + R >> 1;
		j = l;
		k = 0;
		for (i = n; i >= 0; i--) if (j - a[i] > M)
		{
			j = a[i + 1];
			k++;
		}
		if (k > m) L = M + 1;
		else R = M;
	}
	j = l;
	k = 0;
	for (i = n; i >= 0; i--) if (j - a[i] > L)
	{
		j = a[i + 1];
		k++;
	}
	if (k < m) j = a[1];
	printf("%d %d", L, j);
}