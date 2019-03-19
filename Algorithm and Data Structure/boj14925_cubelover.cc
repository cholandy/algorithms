#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	char s[2002];
	int d[2][1001] = {};
	int *p = d[0], *q = d[1], *t;
	int i, n, m, r = 0;
	scanf("%d%d\n", &n, &m);
	while (n--) {
		fgets(s, 2002, stdin);
		for (i = 1; i <= m; i++) {
			q[i] = s[i + i - 2] - 48 ? 0 : min(min(p[i - 1], p[i]), q[i - 1]) + 1;
			if (q[i] > r) r = q[i];
		}
		t = p;
		p = q;
		q = t;
	}
	printf("%d\n", r);
	return 0;
}