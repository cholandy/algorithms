#include<cstdio>

double a[33], s[111];
int sn;
char t[111];

int main()
{
	int i, n;
	scanf("%d%s", &n, t);
	for (i = 1; i <= n; i++) scanf("%lf", &a[i]);
	for (i = 0; t[i]; i++)
	{
		if (t[i] > 64) s[++sn] = a[t[i] & 31];
		else
		{
			if (t[i] == '+') s[sn - 1] += s[sn];
			if (t[i] == '-') s[sn - 1] -= s[sn];
			if (t[i] == '*') s[sn - 1] *= s[sn];
			if (t[i] == '/') s[sn - 1] /= s[sn];
			sn--;
		}
	}
	printf("%.2f", s[1]);
}