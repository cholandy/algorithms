#include <cstdio>

int a[8008];

int main()
{
	int i, n, t, s = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &t);
		s += t;
		a[t + 4004]++;
	}
	printf("%d\n", (s + (s < 0 ? -n / 2 : n / 2)) / n);
	t = n;
	for (i = 0; t > 0; i++) t -= a[i] << 1;
	printf("%d\n", i - 4005);
	t = 0;
	for (i = 0; i < 8008; i++) if (a[t] < a[i]) t = i;
	for (i = t + 1; i < 8008; i++) if (a[i] == a[t]) break;
	printf("%d\n", (i < 8008 ? i : t) - 4004);
	for (i = 0; !a[i]; i++);
	for (t = 8007; !a[t]; t--);
	printf("%d\n", t - i);
}