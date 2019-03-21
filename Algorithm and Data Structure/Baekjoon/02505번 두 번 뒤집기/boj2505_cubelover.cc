#include <cstdio>
#include <algorithm>

using namespace std;

int a[10002], n;
int d[12], dn;

int f()
{
	int i;
	for (i = 0; i < n; i++) if (a[i] != i) return 0;
	return 1;
}

int main()
{
	int i, j, k, l;
	scanf("%d", &n);
	a[n + 1] = n + 1;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
		if (a[i] - a[i - 1] != 1 && a[i - 1] - a[i] != 1)
		{
			d[dn++] = i - 1;
			d[dn++] = i;
		}
	}
	if (a[n] != n) d[dn++] = n;
	n+=2;
	if (f())
	{
		puts("1 1\n1 1");
		return 0;
	}
	for (i = 0; i < dn; i++) for (j = 0; j < i; j++)
	{
		reverse(a + d[j], a + d[i] + 1);
		if (f())
		{
			printf("%d %d\n1 1", d[j], d[i]);
			return 0;
		}
		l = 0;
		for (k = 1; k < n; k++) if (a[k] - a[k - 1] != 1 && a[k - 1] - a[k] != 1) l++;
		if (l > 2)
		{
			reverse(a + d[j], a + d[i] + 1);
			continue;
		}
		printf("%d %d\n", d[j], d[i]);
		for (k = 1; a[k] - a[k - 1] == 1 || a[k - 1] - a[k] == 1; k++);
		printf("%d ", k);
		for (k++; a[k] - a[k + 1] == 1 || a[k + 1] - a[k] == 1; k++);
		printf("%d", k);
		return 0;
	}
	return 0;
}