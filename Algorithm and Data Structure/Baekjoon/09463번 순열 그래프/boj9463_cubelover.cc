#include <cstdio>

char s[700007];

int a[100001];
int d[100001];

inline void readN(int &r)
{
	int t;
	while ((t = getchar()) < 40);
	for (r = t & 15; (t = getchar()) > 40; r = r * 10 + (t & 15));
}

int main()
{
	int t;
	readN(t);
	while (t--)
	{
		char *p;
		long long r;
		int i, j, k, n;
		readN(n);
		fgets(s, 700007, stdin);
		p = s;
		for (i = 1; i <= n; i++)
		{
			for (j = *p & 15; *++p > 40; j = j * 10 + (*p & 15));
			p++;
			a[j] = i;
			d[i] = 0;
		}
		fgets(s, 700007, stdin);
		p = s;
		r = n*(n - 1LL) >> 1;
		for (i = 1; i <= n; i++)
		{
			for (j = *p & 15; *++p > 40; j = j * 10 + (*p & 15));
			p++;
			j = a[j];
			for (k = j; k; k -= k&-k) r -= d[k];
			for (k = j; k <= n; k += k&-k) d[k]++;
		}
		printf("%lld\n", r);
	}
}