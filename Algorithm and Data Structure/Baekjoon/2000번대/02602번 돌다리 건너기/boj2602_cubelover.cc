#include <cstdio>

char a[101], b[101], c[101];
int d[101][2];

int main()
{
	int i, j, n;
	scanf("%s%s%s", a, b, c);
	for (n = 0; a[n]; n++);
	d[0][0] = d[0][1] = 1;
	for (i = 0; b[i]; i++) for (j = n - 1; j >= 0;j--)
	{
		if (b[i] == a[j]) d[j + 1][1] += d[j][0];
		if (c[i] == a[j]) d[j + 1][0] += d[j][1];
	}
	printf("%d", d[n][0] + d[n][1]);
}