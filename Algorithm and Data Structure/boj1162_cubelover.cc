#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

vector<pair<int, int> > g[222222];
long long d[222222];

int main()
{
	priority_queue<pair<long long, int> > pq;
	pair<long long, int> p;
	int i, j, k, n, m, l, t;
	scanf("%d%d%d", &n, &m, &l);
	for (i = 1; i <= n; i++) for (t = 0; t < l; t++) g[t*n + i].push_back(make_pair(t*n + i + n, 0));
	while (m--)
	{
		scanf("%d%d%d", &i, &j, &k);
		for (t = 0; t <= l; t++)
		{
			g[t*n + i].push_back(make_pair(t*n + j, k));
			g[t*n + j].push_back(make_pair(t*n + i, k));
		}
		for (t = 0; t < l; t++)
		{
			g[t*n + i].push_back(make_pair(t*n + j + n, 0));
			g[t*n + j].push_back(make_pair(t*n + i + n, 0));
		}
	}
	for (i = 1; i <= n*l + n; i++) d[i] = 9e18;
	pq.push(make_pair(0, 1));
	while (!pq.empty())
	{
		p = pq.top();
		pq.pop();
		if (d[p.second] + p.first < 0)continue;
		for (i = 0; i < g[p.second].size(); i++) if (d[g[p.second][i].first]>g[p.second][i].second - p.first)
		{
			d[g[p.second][i].first] = g[p.second][i].second - p.first;
			pq.push(make_pair(p.first - g[p.second][i].second, g[p.second][i].first));
		}
	}
	printf("%lld", d[n*l + n]);
}