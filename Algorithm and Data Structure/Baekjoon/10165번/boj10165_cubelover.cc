#include <cstdio>
#include <algorithm>

using namespace std;

pair<pair<int, int>, int> d[1000001];
char v[500005];

int main()
{
	int i, j, k, n, m;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &j, &k);
		if (j > k) j -= n;
		d[i << 1].first.first = j;
		d[i << 1].first.second = -k;
		d[i << 1].second = i;
		d[i << 1 | 1].first.first = j + n;
		d[i << 1 | 1].first.second = -k - n;
		d[i << 1 | 1].second = i;
	}
	sort(d, d + m + m);
	j = -1;
	for (i = 0; i < m + m; i++)
	{
		if (-d[i].first.second <= j) v[d[i].second] = 1;
		else j = -d[i].first.second;
	}
	for (i = 0; i < m; i++) if (!v[i]) printf("%d ", i + 1);
}