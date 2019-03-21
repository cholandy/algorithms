#include <cstdio>
#include <algorithm>

using namespace std;

int a[101], b[101];
int p[101];

int f(int x)
{
	return x == p[x] ? x : p[x] = f(p[x]);
}

int main()
{
	int tcn;
	scanf("%d", &tcn);
	while (tcn--)
	{
		int i, j, n;
		scanf("%d", &n);
		n += 2;
		for (i = 0; i < n; i++)
		{
			scanf("%d%d", a + i, b + i);
			p[i] = i;
			for (j = 0; j < i; j++) if (abs(a[i] - a[j]) + abs(b[i] - b[j]) <= 1000) p[f(j)] = i;
		}
		puts(f(0) == n - 1 ? "happy" : "sad");
	}
	return 0;
}