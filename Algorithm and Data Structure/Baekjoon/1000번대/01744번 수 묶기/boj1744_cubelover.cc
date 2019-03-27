#include <cstdio>
#include <algorithm>

using namespace std;

int a[10001];
long long d[10001];

int main()
{
	int i, n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	for (i = 1; i <= n; i++)
	{
		d[i] = d[i - 1] + a[i];
		if (i > 1 && d[i] < d[i - 2] + a[i - 1] * a[i]) d[i] = d[i - 2] + a[i - 1] * a[i];
	}
	printf("%lld", d[n]);
}