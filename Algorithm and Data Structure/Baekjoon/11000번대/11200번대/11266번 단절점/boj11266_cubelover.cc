#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> g[10001];
int d[10001];
int v[10001];
int p[10001];
int s[10001], sn;

void f(int x, int y)
{
	int i, t = 0, u = x != y;
	v[x] = 1;
	d[x] = p[x] = d[y] + 1;
	for (i = 0; i < g[x].size(); i++) if (g[x][i] != y)
	{
		if (!v[g[x][i]])
		{
			u++;
			f(g[x][i], x);
			if (p[g[x][i]] < p[x]) p[x] = p[g[x][i]];
			if (p[g[x][i]] >= d[x]) t = 1;
		}
		else if (d[g[x][i]] < p[x]) p[x] = d[g[x][i]];
	}
	if (t && u > 1) s[sn++] = x;
}

int main()
{
	int i, j, n, m;
	scanf("%d%d", &n, &m);
	while (m--)
	{
		scanf("%d%d", &i, &j);
		g[i].push_back(j);
		g[j].push_back(i);
	}
	for (i = 1; i <= n; i++) if (!v[i]) f(i, i);
	sort(s, s + sn);
	printf("%d\n", sn);
	for (i = 0; i < sn; i++) printf("%d ", s[i]);
}