#include <stdio.h>
#include <algorithm>

int n, l, a[1001];

int main() {
	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	
	std::sort(a, a + n);
	
	int tmp = a[0], cnt = 1;
	for (int i = 0; i < n; i++)
		if (tmp + l - 1 < a[i]) tmp = a[i], cnt++;

	printf("%d", cnt);

	return 0;
}