#include <cstdio>

int f(int x, int y) {
	return x ? f(y % x, x) : y;
}

int main() {
	int n, m, l;
	scanf("%d:%d", &n, &m);
	l = f(n, m);
	printf("%d:%d", n / l, m / l);
	return 0;
}
