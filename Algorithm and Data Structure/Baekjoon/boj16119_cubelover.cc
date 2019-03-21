#pragma GCC optimize("Ofast")
#include <cstdio>

int a[1001][1001];
int d[1001][1001];

int main() {
	int i, j, k, n, t;
	scanf("%d", &n);
	for (i = 0; i < n; i++) for (j = 0; j < n; j++) scanf("%d", &a[i][j]);
	for (i = 0; i < n; i++) for (j = 0; j < n; j++) {
		for (k = t = 0; k < 31; k++) {
			if (j + k < n && a[i][j + k] > t) t = a[i][j + k];
			if (j >= k && a[i][j - k] > t) t = a[i][j - k];
			if (i + k < n && d[i + k][j] < t - (k + 1) * (k + 1)) d[i + k][j] = t - (k + 1) * (k + 1);
			if (i >= k && d[i - k][j] < t - (k + 1) * (k + 1)) d[i - k][j] = t - (k + 1) * (k + 1);
		}
		for (k = t = 0; k < 31; k++) {
			if (i + k < n && a[i + k][j] > t) t = a[i + k][j];
			if (i >= k && a[i - k][j] > t) t = a[i - k][j];
			if (j + k < n && d[i][j + k] < t - (k + 1) * (k + 1)) d[i][j + k] = t - (k + 1) * (k + 1);
			if (j >= k && d[i][j - k] < t - (k + 1) * (k + 1)) d[i][j - k] = t - (k + 1) * (k + 1);
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) printf("%d ", d[i][j]);
		puts("");
	}
	return 0;
}
