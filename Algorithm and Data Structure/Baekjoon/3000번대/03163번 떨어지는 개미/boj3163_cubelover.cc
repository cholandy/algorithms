#include <cstdio>
#include <algorithm>

using namespace std;

pair<int, int> a[100001];
int b[100001];

inline void readN(int &r)
{
	int t;
	while ((t = getchar()) < 40);
	for (r = t & 15; (t = getchar()) > 40; r = r * 10 + (t & 15));
}

inline void readZ(int &r)
{
	int t, m = 0;
	while ((t = getchar()) < 40);
	if (t == 45)
	{
		m = 1;
		t = getchar();
	}
	for (r = t & 15; (t = getchar()) > 40; r = r * 10 + (t & 15));
	if (m) r = -r;
}

int main()
{
	int t;
	readN(t);
	while (t--)
	{
		int i, n, m, l;
		readN(n);
		readN(m);
		readN(l);
		for (i = 0; i < n; i++)
		{
			readN(a[i].first);
			readZ(a[i].second);
			if (a[i].second < 0) b[i] = -m + a[i].first;
			else b[i] = a[i].first;
		}
		sort(b, b + n);
		for (i = 0; i < n; i++)
		{
			if (b[i] < 0) a[i].first = m + b[i];
			else a[i].first = m - b[i];
		}
		nth_element(a, a + --l, a + n);
		printf("%d\n", a[l].second);
	}
}