#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > g[20002];
int a[20002];
int d[20002];
int v[20002];
int s[20002], sn;

void f(int x) {
	if (v[x]) return;
	d[x] = -2e9;
	v[x] = 1;
	for (auto t : g[x]) {
		f(t.first);
		d[x] = max(d[x], d[t.first] - t.second);
	}
	d[x] += a[x];
}

void h(int x) {
	for (auto t : g[x]) if (d[x] == d[t.first] - t.second + a[x]) {
		h(t.first);
		break;
	}
	s[sn++] = x;
}

int main() {
	int Tn;
	scanf("%d", &Tn);
	while (Tn--) {
		int i, j, k, l, m, n, r;
		scanf("%d%d", &n, &m);
		for (i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			v[i] = 0;
			g[i].clear();
		}
		while (m--) {
			scanf("%d%d%d", &i, &j, &k);
			g[j].emplace_back(i, k);
		}
		v[1] = 1;
		d[1] = a[1];
		r = -2e9;
		for (i = 1; i <= n; i++) {
			f(i);
			if (d[i] > r) {
				r = d[i];
				j = i;
			}
		}
		sn = 0;
		h(j);
		printf("%d %d\n", r, sn);
		for (i = 0; i < sn; i++) printf("%d ", s[i]);
		puts("");
	}
	return 0;
}