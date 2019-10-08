#include <cstdio>

int a[100001];

int main() {
	int i, Tn;
	a[0] = 1;
	for (i = 1; i <= 100000; i++) a[i] = (long long)i * a[i - 1] % 1000000007;
	scanf("%d", &Tn);
	while (Tn--) {
		scanf("%d", &i);
		printf("%d\n", a[i] - 1);
	}
}