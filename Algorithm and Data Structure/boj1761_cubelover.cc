#include <cstdio>
#include <vector>

using namespace std;

vector<pair<int, int> > g[40004];
int v[40004];
int p[20][40004];
int q[20][40004];

void f(int x, int y)
{
	int i;
	p[0][x] = y;
	for (i = 1; i < 20; i++)
	{
		p[i][x] = p[i - 1][p[i - 1][x]];
		q[i][x] = q[i - 1][x] + q[i - 1][p[i - 1][x]];
	}
	for (i = 0; i < g[x].size(); i++) if (g[x][i].first != y)
	{
		v[g[x][i].first] = v[x] + 1;
		q[0][g[x][i].first] = g[x][i].second;
		f(g[x][i].first, x);
	}
}

int main()
{
	int i, j, k, l, n;
	scanf("%d", &n);
	for (i = 1; i < n; i++)
	{
		scanf("%d%d%d", &j, &k, &l);
		g[j].push_back(make_pair(k, l));
		g[k].push_back(make_pair(j, l));
	}
	f(1, 1);
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d%d", &i, &j);
		if (v[i] < v[j]) swap(i, j);
		k = 0;
		for (l = 19; l >= 0; l--) if (v[i] - v[j] >> l)
		{
			k += q[l][i];
			i = p[l][i];
		}
		for (l = 19; l >= 0; l--) if (p[l][i] != p[l][j])
		{
			k += q[l][i] + q[l][j];
			i = p[l][i];
			j = p[l][j];
		}
		while (i != j)
		{
			k += q[0][i] + q[0][j];
			i = p[0][i];
			j = p[0][j];
		}
		printf("%d\n", k);
	}
}