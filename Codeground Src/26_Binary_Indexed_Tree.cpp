#include <stdio.h>

#define MAX 50005

int T[MAX];

void Update(int p, int v, int S) {
	while (p <= S) {
		T[p] += v;
		p += p & (-p);
	}
}

int Sum(int p) {
	int ret = 0;
	while (p > 0) {
		ret += T[p];
		p -= p & (-p);
	}
	return ret;
}

int main() {
	int n, m; 
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		Update(i, x, n);
	}
	scanf("%d", &m);
	while (m--) {
		int x; scanf("%d", &x);
		printf("%d\n", Sum(x));
	}
}