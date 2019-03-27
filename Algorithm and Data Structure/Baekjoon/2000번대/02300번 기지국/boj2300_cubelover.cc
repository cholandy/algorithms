#include <cstdio>
#include <algorithm>

using namespace std;

pair<int, int> a[10001];
int d[10001];

int main() {
	int i, j, k, t, n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d%d", &a[i].first, &a[i].second);
		if (a[i].second < 0) a[i].second = -a[i].second;
		a[i].second <<= 1;
	}
	sort(a + 1, a + n + 1);
	for (i = 1; i <= n; i++) {
		d[i] = 1e9;
		k = 0;
		for (j = i; j > 0; j--) {
			if (a[j].second > k) k = a[j].second;
			t = d[j - 1] + max(a[i].first - a[j].first, k);
			if (t < d[i]) d[i] = t;
		}
	}
	printf("%d", d[n]);
}