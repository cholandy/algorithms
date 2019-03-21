#include <cstdio>
#include <algorithm>

using namespace std;

int a[100000];

int main() {
	long long r = 0;
	int i, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	for (i = 0; i < n; i++) if (i % 3 != 2) r += a[n - i - 1];
	printf("%lld", r);
}