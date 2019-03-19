#include <cstdio>
#include <algorithm>

using namespace std;
pair<int, int> a[4];

long long f(int i, int j)
{
	return (long long)(a[i].first - a[j].first)*(a[i].first - a[j].first) + (long long)(a[i].second - a[j].second)*(a[i].second - a[j].second);
}

int main()
{
	int tcn;
	scanf("%d", &tcn);
	while (tcn--)
	{
		long long t;
		int i;
		for (i = 0; i < 4; i++) scanf("%d%d", &a[i].first, &a[i].second);
		sort(a, a + 4);
		i = 0;
		do
		{
			t = f(0, 3);
			if (t && t == f(0, 1) && t == f(1, 2) && t == f(2, 3) && f(0, 2) == f(1, 3)) i = 1;
		} while (next_permutation(a, a + 4));
		putchar(i | 48);
		putchar(10);
	}
}