#include <cstdio>
#include <vector>

using namespace std;

vector<int> g[50005];
int v[50005];

int p[16][50005];

void f(int x)
{
	int i;
	for (i = 1; i < 16; i++) p[i][x] = p[i - 1][p[i - 1][x]];
	for (i = 0; i < g[x].size(); i++) if (!v[g[x][i]])
	{
		v[g[x][i]] = v[x] + 1;
		p[0][g[x][i]] = x;
		f(g[x][i]);
	}
}

int main()
{
	int i, j, k, n;
	scanf("%d", &n);
	while (--n)
	{
		scanf("%d%d", &i, &j);
		g[i].push_back(j);
		g[j].push_back(i);
	}
	v[1] = 1;
	f(1);
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d%d", &i, &j);
		if (v[i] < v[j]) swap(i, j);
		for (k = 15; k >= 0; k--) if (v[i] - v[j] >> k) i = p[k][i];
		for (k = 15; k >= 0; k--) if (p[k][i] != p[k][j])
		{
			i = p[k][i];
			j = p[k][j];
		}
		while (i != j)
		{
			i = p[0][i];
			j = p[0][j];
		}
		printf("%d\n", i);
	}
}