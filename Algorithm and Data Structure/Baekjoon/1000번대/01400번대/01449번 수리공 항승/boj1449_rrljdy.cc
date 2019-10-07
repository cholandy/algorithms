#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int n, l;
	scanf("%d %d", &n, &l);
	int *a = new int[n];
	for (int i = 0;i < n;i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int ans = 0;
	int temp = a[0];
	for (int i = 0;i < n;i++) {
		if (a[i] <= l - 1 + temp) {
			continue;
		}
		ans++;
		temp = a[i];
	}
	printf("%d\n", ans+1);
	return 0;
}