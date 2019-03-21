#include<cstdio>

const int o = 1048576;

int a[2100000];

int main()
{
	int i, j, k, n;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &i);
		if (i == 1)
		{
			scanf("%d", &j);
			k = 1;
			while (k < o)
			{
				if (a[k << 1] < j)
				{
					j -= a[k << 1];
					k = k << 1 | 1;
				}
				else k <<= 1;
			}
			printf("%d\n", k - o);
			while (k)
			{
				a[k]--;
				k >>= 1;
			}
		}
		else
		{
			scanf("%d%d", &j, &k);
			j += o;
			while (j)
			{
				a[j] += k;
				j >>= 1;
			}
		}
	}
}