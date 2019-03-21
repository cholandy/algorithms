#include <unistd.h>
#include <cstdio>

char s[1680000], *p = s;

inline int getInt() {
	int r = *p++ & 15;
	char c;
	while ((c = *p++) > 40) r = r * 10 + (c & 15);
	return r;
}

int a[200000];

int main() {
	int tj, tk, t;
	int i, j, k, n, m;
	syscall(0, 0, s, sizeof(s));
	n = getInt();
	for (i = 0; i < n; i++) a[i + n] = getInt();
	if (*p < 40) p++;
	for (i = n; --i; a[i] = a[i << 1] < a[i << 1 | 1] ? a[i << 1] : a[i << 1 | 1]);
	m = getInt();
	while (m--) {
		if (getInt() == 1) {
			j = getInt() + n - 1;
			a[j] = getInt();
			while (j >>= 1) a[j] = a[j << 1] < a[j << 1 | 1] ? a[j << 1] : a[j << 1 | 1];
		}
		else {
			j = getInt() + n - 1;
			k = getInt() + n - 1;
			tj = j;
			tk = k;
			t = 2e9;
			while (tj <= tk) {
				if (t > a[tj]) t = a[tj];
				if (t > a[tk]) t = a[tk];
				tj = ++tj >> 1;
				tk = --tk >> 1;
			}
			while (a[j] > t) j = ++j >> 1;
			while (j < n) j = j << 1 | (a[j << 1] > t);
			printf("%d\n", j - n + 1);
		}
	}
	return 0;
}
