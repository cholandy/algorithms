#include <cstdio>
#include <algorithm>
int n, k, a, ans = 1e9;
int main() {
	scanf("%d %d %d", &n, &k, &a);
	for (int i = 0; i < n; i++) {
		int t, s;
		scanf("%d %d", &t, &s);
		ans = std::min(ans, k/a+(k/(a*t)+(k%(a*t)?0:-1))*s);
	}
	printf("%d", ans);
	return 0;
}