#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int MAX_V = 152, INF = 1e9;
int min_v(int a, int b) { return a < b ? a : b; }
struct Edge {
	int v, f, c, rn;
	Edge() { }
	Edge(int v, int f, int c, int rn)
		: v(v), f(f), c(c), rn(rn) {}
	int rc() { return c - f; }
	void af(int amt, vector<Edge> adj[MAX_V]) {
		f += amt;
		adj[v][rn].f -= amt;
	}
};
vector<Edge> adj[MAX_V];
void addEdge(int u, int v, int c) {
	adj[u].push_back(Edge(v, 0, c, (int)adj[v].size()));
	adj[v].push_back(Edge(u, 0, 0, (int)adj[u].size() - 1));
}
int usedEdge[MAX_V], level[MAX_V];
queue<int> q;
bool bfs(int& S, int &T) {
	memset(level, -1, sizeof level);
	level[S] = 0;
	q.push(S);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (Edge& e : adj[u]) if (e.rc() > 0 && level[e.v] == -1) {
			level[e.v] = level[u] + 1;
			q.push(e.v);
		}
	}
	return level[T] != -1;
}
int dfs(int u, const int& T, int f) {
	if (u == T) return f;
	int d;
	for (int& i = usedEdge[u]; i < (int)adj[u].size(); i++) {
		Edge& e = adj[u][i];
		if (e.rc() > 0 && level[e.v] > level[u]) {
			d = dfs(e.v, T, min_v(f, e.rc()));
			if (d > 0) {
				e.af(d, adj);
				return d;
			}
		}
	}
	return 0;
}
int main() {
	int n, m, f, cnt, i, d, S, T, l, r, mid,flows,fd;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &m, &f);
		S = m + f, T = m + f + 1;
		for (i = 0; i <= T; i++)
			adj[i].clear(), adj[i].resize(0);
		for (i = 0; i < m; i++)
			addEdge(f + i, T, 1);
		for (i = 0; i < f; i++) {
			addEdge(S, i, 0);
			scanf("%d", &cnt);
			while (cnt--) {
				scanf("%d", &d);
				addEdge(i, f + d, 1);
			}
		}
		l = 0, r = 101;
		while (l <= r) {
			mid = (l + r) / 2;
			for (i = 0; i <= T; i++)
				for (Edge& e : adj[i]) e.f = 0;

			for (i = 0; i < f; i++)
				adj[S][adj[i].front().rn].c = mid;
			flows = 0;
			while (bfs(S, T)) {
				memset(usedEdge, 0, sizeof usedEdge);
				while ((fd = dfs(S, T, INF)) > 0)
					flows += fd;
			}
			if (flows == m) r = mid - 1;
			else l = mid + 1;
		}
		if (l > 100) puts("impossible");
		else printf("%d\n", l);
	}
	return 0;
}