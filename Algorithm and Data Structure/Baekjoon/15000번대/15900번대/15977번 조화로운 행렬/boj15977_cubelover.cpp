#pragma GCC optimize("O3")
#pragma GCC target("arch=skylake")
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

pair<int, pair<int, int> > a[200002];
set<pair<int, int> > S[200002];

int main() {
	int L, R, M, r = 0;
	int i, j, n, m;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++) scanf("%d", &a[i].first);
	for (i = 0; i < m; i++) scanf("%d", &a[i].second.first);
	if (n == 3) for (i = 0; i < m; i++) scanf("%d", &a[i].second.second);
	else for (i = 0; i < m; i++) a[i].second.second = a[i].second.first;
	sort(a, a + m);
	for (i = 0; i < m; i++) {
		L = 1;
		R = r + 1;
		while (L < R) {
			M = L + R >> 1;
			auto it = S[M].lower_bound(a[i].second);
			if (it == S[M].begin()) {
				R = M;
				continue;
			}
			it--;
			if (it->second < a[i].second.second) L = M + 1;
			else R = M;
		}
		if (L > r) r = L;
		auto it = S[L].insert(a[i].second).first;
		it++;
		while (it != S[L].end() && it->second > a[i].second.second) {
			auto tit = it;
			it++;
			S[L].erase(tit);
		}
	}
	printf("%d\n", r);
}