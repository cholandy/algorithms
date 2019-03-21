#include <cstdio>
#include <vector>

using namespace std;

vector<int> g[50005], h[50005];
int v[50005];

void dfs1(int x) {
	if (v[x] & 1) return;
	v[x] |= 1;
	for (auto t : g[x]) dfs1(t);
}

void dfs2(int x) {
	if (v[x] & 2) return;
	v[x] |= 2;
	for (auto t : h[x]) dfs2(t);
}

int dfs3(int x) {
	if (v[x] == -1) return 1;
	if (v[x]) return 0;
	v[x] = -1;
	for (auto t : g[x]) if (dfs3(t)) return 1;
	v[x] = 1;
	return 0;
}

int main() {
	int i, j, n, m;
	scanf("%d", &n);
	for (i = 1; i < n; i++) {
		scanf("%d", &m);
		while (m--) {
			scanf("%d", &j);
			g[i].push_back(j);
			h[j].push_back(i);
		}
	}
	dfs1(1);
	dfs2(n);
	for (i = 1; i <= n; i++) if (v[i] == 1) break;
	printf(i > n ? "PARDON " : "PRISON ");
	for (i = 1; i <= n; i++) v[i] = 0;
	puts(dfs3(1) ? "UNLIMITED" : "LIMITED");
}