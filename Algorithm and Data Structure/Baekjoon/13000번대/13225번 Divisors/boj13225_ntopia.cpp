#include <cstdio>
using namespace std;

void proc() {
	int n;
	scanf("%d", &n);

	int cnt = 0;
	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			++cnt;
			if (i * i < n) {
				++cnt;
			}
		}
	}
	printf("%d %d\n", n, cnt);
}

int main() {
	//freopen("input.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		proc();
	}
	return 0;
}