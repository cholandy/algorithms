#include <cstdio>
#include <vector>
#include <algorithm>

const int INF = 987654321;

using namespace std;

vector<pair<int, int> > g[100001];
int d[100001];
int p[100001][17], q[100001][17], r[100001][17];

void f(int x, int y) {
	int i;
	for (i = 1; i < 17; i++) {
		p[x][i] = p[p[x][i - 1]][i - 1];
		q[x][i] = min(q[x][i - 1], q[p[x][i - 1]][i - 1]);
		r[x][i] = max(r[x][i - 1], r[p[x][i - 1]][i - 1]);
	}
	for (i = 0; i < g[x].size(); i++) if (g[x][i].first != y) {
		d[g[x][i].first] = d[x] + 1;
		p[g[x][i].first][0] = x;
		q[g[x][i].first][0] = r[g[x][i].first][0] = g[x][i].second;
		f(g[x][i].first, x);
	}
}

int main() {
	int i, j, k, l, n, t;
	scanf("%d", &n);
	while (--n) {
		scanf("%d%d%d", &j, &k, &l);
		g[j].push_back(pair<int, int>(k, l));
		g[k].push_back(pair<int, int>(j, l));
	}
	p[1][0] = 1;
	f(1, 1);
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &i, &j);
		if (d[i] < d[j]) swap(i, j);
		k = INF;
		l = 0;
		for (t = 16; t >= 0; t--) if (d[i] - d[j] >> t) {
			if (q[i][t] < k) k = q[i][t];
			if (r[i][t] > l) l = r[i][t];
			i = p[i][t];
		}
		for (t = 16; t >= 0; t--) if (p[i][t] != p[j][t]) {
			k = min(k, min(q[i][t], q[j][t]));
			l = max(l, max(r[i][t], r[j][t]));
			i = p[i][t];
			j = p[j][t];
		}
		if (i != j) {
			k = min(k, min(q[i][0], q[j][0]));
			l = max(l, max(r[i][0], r[j][0]));
		}
		printf("%d %d\n", k, l);
	}
}