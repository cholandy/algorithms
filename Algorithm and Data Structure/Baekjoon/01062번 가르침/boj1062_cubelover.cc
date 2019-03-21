#include <cstdio>
#include <algorithm>

using namespace std;

char *t = "bdefghjklmopqrsuvwxyz";
char s[55][22];
char a[22] ,p[33];

int main()
{
	int i, j, k, n, m, r = 0;
	scanf("%d%d", &n, &m);
	if (m < 5)
	{
		putchar(48);
		return 0;
	}
	m -= 5;
	for (i = 0; i < n; i++) scanf("%s", s + i);
	for (i = 0; i < 33; i++) p[i] = -1;
	for (i = 0; t[i]; i++) p[t[i] & 31] = i;
	for (i = 0; i < m; i++) a[i] = 1;
	do
	{
		k = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; s[i][j]; j++) if (p[s[i][j] & 31] >= 0 && !a[p[s[i][j] & 31]]) break;
			if (!s[i][j]) k++;
		}
		r = max(r, k);
	} while (prev_permutation(a, a + 21));
	printf("%d", r);
}