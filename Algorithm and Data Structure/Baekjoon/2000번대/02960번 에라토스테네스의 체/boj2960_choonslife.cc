#include <iostream>
using namespace std;
int n, k;
bool num[1010];
void dele(int x) {
	for (int i = 1;; i++) {
		if (i*x > n) return;
		else {
			if (!num[i*x]) {
				num[i*x] = true;
				k--;
			}
			if (k == 0) {
				printf("%d\n", i*x);
				return;
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 2; i <= n; i++) {
		if (!num[i])
			dele(i);
	}
	return 0;
}