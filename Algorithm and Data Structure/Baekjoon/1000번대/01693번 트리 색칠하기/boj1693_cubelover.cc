#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> g[100001];
int d[100001][22];
int L[22], R[22];

void f(int x, int y)
{
	int i, j;
	for (j = 0; j < 22; j++) d[x][j] = j + 1;
	for (i = 0; i < g[x].size(); i++) if (g[x][i] != y)
	{
		f(g[x][i], x);
		L[0] = 1e9;
		for (j = 0; j < 21; j++) L[j + 1] = min(L[j], d[g[x][i]][j]);
		R[21] = 1e9;
		for (j = 21; j > 0; j--) R[j - 1] = min(R[j], d[g[x][i]][j]);
		for (j = 0; j < 22; j++) d[x][j] += min(L[j], R[j]);
	}
}

int main()
{
	int i, j, n;
	scanf("%d", &n);
	while (--n)
	{
		scanf("%d%d", &i, &j);
		g[i].push_back(j);
		g[j].push_back(i);
	}
	f(1, 1);
	printf("%d", *min_element(d[1], d[1] + 22));
}