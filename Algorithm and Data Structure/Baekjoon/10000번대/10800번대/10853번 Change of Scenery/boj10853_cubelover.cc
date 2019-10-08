#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int> > g[10001];
int v[10001];
int d[10001];

int main() {
	priority_queue<pair<int, pair<int, int> > > pq;
	int i, j, k, n, m, l;
	scanf("%d%d%d", &n, &m, &l);
	while (l--) scanf("%*d");
	while (m--) {
		scanf("%d%d%d", &i, &j, &k);
		g[i].push_back(make_pair(j, k));
		g[j].push_back(make_pair(i, k));
	}
	v[0] = 1;
	pq.push(make_pair(0, make_pair(1, 0)));
	while (!pq.empty()) {
		pair<int, pair<int, int> > p = pq.top();
		pq.pop();
		int t = p.second.first;
		if (v[t]) {
			if (d[t] == -p.first) {
				v[t] += v[p.second.second];
				if (v[t] > 2) v[t] = 2;
			}
			continue;
		}
		v[t] += v[p.second.second];
		if (v[t] > 2) v[t] = 2;
		d[t] = -p.first;
		for (i = 0; i < g[t].size(); i++) pq.push(make_pair(p.first - g[t][i].second, make_pair(g[t][i].first, t)));
	}
	puts(v[n] > 1 ? "yes" : "no");
	return 0;
}