#pragma GCC optimize("O3")
#pragma GCC target("arch=skylake")
#include <cstdio>

inline int f(char c) {
	return (c > 'c') + (c > 'f') + (c > 'i') + (c > 'l') + (c > 'o') + (c > 'v');
}

int main() {
	char s[101];
	int a[11], b[33];
	int i, j, k, t = -1;
	for (i = 1; i <= 9; i++) {
		scanf("%d", &j);
		a[j] = i;
	}
	scanf("%s", s);
	for (i = 0; s[i]; i++) {
		j = s[i] - 'a' + f(s[i]);
		if (t == j / 4) putchar('#');
		t = j / 4;
		for (k = 0; k <= j % 4; k++) putchar(a[t + 2] + 48);
	}
	return 0;
}
