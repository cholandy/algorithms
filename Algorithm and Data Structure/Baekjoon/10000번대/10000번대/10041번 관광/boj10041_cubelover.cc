#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int i, j, k, l, n, r = 0;
	scanf("%*d%*d%d%d%d", &n, &i, &j);
	while (--n)
	{
		scanf("%d%d", &k, &l);
		r += min(abs(i - k) + abs(j - l), min(abs(i - k), abs(j - l)) + abs(i - j - k + l));
		i = k;
		j = l;
	}
	printf("%d", r);
}