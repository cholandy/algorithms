#include <cstdio>
#include <algorithm>

using namespace std;

pair<int, pair<int, int> > a[100001];
int p[100001];

int f(int x) {
	return x == p[x] ? x : p[x] = f(p[x]);
}

int main() {
	int i, j, k, l, m, n;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++) scanf("%d%d%d", &a[i].second.first, &a[i].second.second, &a[i].first);
	scanf("%d%d", &j, &k);
	sort(a, a + m);
	for (i = 1; i <= n; i++) p[i] = i;
	for (i = m - 1; i >= 0 && f(j) != f(k); i--) if (f(a[i].second.first) != f(a[i].second.second)) p[f(a[i].second.first)] = f(a[i].second.second);
	printf("%d", a[i + 1].first);
}