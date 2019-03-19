#include <cstdio>

char s[15000000];

inline void init() { fread(s, 1, sizeof(s), stdin); }
inline void readN(int &r)
{
	static char *p = s;
	while (*p < 48) p++;
	for (r = *p & 15; *++p & 16; r = r * 10 + (*p & 15));
}

int p[2000002];
int q[2000002];
int r;

int g[1000001];
int c[1000001];
int d[1000001];

void f(int x, int y)
{
	int i, j = 0, k = 1;
	for (i = g[x]; i; i = q[i]) if (p[i] != y)
	{
		f(p[i], x);
		j += d[p[i]];
		k += c[p[i]] < d[p[i]] ? c[p[i]] : d[p[i]];
	}
	c[x] = j;
	d[x] = k;
}

int main()
{
	int i, j, n;
	init();
	readN(n);
	while (--n)
	{
		readN(i);
		readN(j);
		r++;
		p[r] = j;
		q[r] = g[i];
		g[i] = r;
		r++;
		p[r] = i;
		q[r] = g[j];
		g[j] = r;
	}
	f(1, 1);
	printf("%d", c[1] < d[1] ? c[1] : d[1]);
}