#include <cstdio>

int a[100][100];

int main() {
	int i, j, k, l, m, n, r = 0;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) for (j = 0; j < n; j++) scanf("%d", &a[i][j]);
	for (i = 0; i < n; i++) {
		k = a[i][0];
		l = 1;
		for (j = 1; j < n; j++) {
			if (a[i][j] > k + 1 || a[i][j] < k - 1) break;
			if (a[i][j] == k + 1) {
				if (l < m) break;
				k = a[i][j];
				l = 1;
			}
			else if (a[i][j] == k) l++;
			else if (a[i][j] == k - 1) {
				if (l < 0) break;
				k = a[i][j];
				l = 1 - m;
			}
		}
		if (j == n && l >= 0) r++;
	}
	for (j = 0; j < n; j++) {
		k = a[0][j];
		l = 1;
		for (i = 1; i < n; i++) {
			if (a[i][j] > k + 1 || a[i][j] < k - 1) break;
			if (a[i][j] == k + 1) {
				if (l < m) break;
				k = a[i][j];
				l = 1;
			}
			else if (a[i][j] == k) l++;
			else if (a[i][j] == k - 1) {
				if (l < 0) break;
				k = a[i][j];
				l = 1 - m;
			}
		}
		if (i == n && l >= 0) r++;
	}
	printf("%d\n", r);
	return 0;
}
