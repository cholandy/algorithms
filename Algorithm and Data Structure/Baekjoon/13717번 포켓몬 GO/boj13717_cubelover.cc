#pragma GCC optimize("Os")
#pragma GCC target("arch=skylake")
#include <cstdio>
#include <cstring>

int main() {
	char s[22], t[22];
	int m = -1;
	int i, j, k, n, r = 0;
	scanf("%d", &n);
	while (n--) {
		scanf("%s%d%d", s, &i, &j);
		r += k = (j - 2) / (i - 2);
		if (k > m) {
			m = k;
			strcpy(t, s);
		}
	}
	printf("%d\n%s\n", r, t);
	return 0;
}
