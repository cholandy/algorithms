#include <cstdio>
int n, k, t, d[100001];
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= k; i++) {
        d[i] = 1e9;
    }
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		for (int j = t; j <= k; j++) {
			d[j] = (d[j-t]+1 <= d[j]) ? d[j-t]+1 : d[j];
        }
	}
	printf("%d\n", (d[k] == 1e9) ? -1 : d[k]);
	return 0;
}