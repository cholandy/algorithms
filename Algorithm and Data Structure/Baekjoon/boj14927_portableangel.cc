#include <stdio.h>

int a[18][18], n, b[18][18];

int process(int h) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0) {
				int c = 0;
				if (j && (h&(1 << (j - 1)))) c++;
				if (h&(1 << j)) c++;
				if (j < (n - 1) && (h&(1 << (j + 1)))) c++;
				if (c % 2) b[i][j] = a[i][j] ^ 1;
				else b[i][j] = a[i][j];
			}
			else if (i == 1) {
				if (h&(1 << j)) b[i][j] = a[i][j] ^ 1;
				else b[i][j] = a[i][j];
			}
			else b[i][j] = a[i][j];
		}
	}
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (b[i - 1][j]) {
				cnt++;
				if (j) b[i][j - 1] ^= 1;
				b[i][j] ^= 1;
				if (j < n - 1) b[i][j + 1] ^= 1;
				if (i < n - 1) b[i + 1][j] ^= 1;
			}
		}
	}
	for (int j = 0; j < n; j++) {
		if (b[n - 1][j]) return (1 << 30);
	}
	return cnt;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	}
	int res = (1 << 30);
	for (int i = 0; i < (1 << n); i++) {
		int w = 0, t = i;
		while (t) {
			w++; t -= t&-t;
		}
		w += process(i);
		if (w < res) res = w;
	}
	if (res == (1 << 30)) res = -1;
	printf("%d\n", res);
	return 0;
}