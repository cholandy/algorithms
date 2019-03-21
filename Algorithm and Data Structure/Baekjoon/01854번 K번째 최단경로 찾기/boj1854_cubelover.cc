#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

priority_queue<pair<int, int> > pq;
vector<pair<int, int> > g[1001];
int d[1001][101];
int dn[1001];

int main()
{
	pair<int, int> p;
	int i, j, k, l, m, n;
	scanf("%d%d%d", &n, &m, &l);
	while (m--)
	{
		scanf("%d%d%d", &i, &j, &k);
		g[i].push_back(make_pair(j, k));
	}
	dn[1] = 0;
	pq.push(make_pair(0, 1));
	while (!pq.empty())
	{
		p = pq.top();
		pq.pop();
		if (dn[p.second] == l) continue;
		d[p.second][dn[p.second]++] = -p.first;
		for (i = 0; i < g[p.second].size(); i++) pq.push(make_pair(p.first - g[p.second][i].second, g[p.second][i].first));
	}
	for (i = 1; i <= n; i++) printf("%d\n", dn[i] == l ? d[i][l - 1] : -1);
}