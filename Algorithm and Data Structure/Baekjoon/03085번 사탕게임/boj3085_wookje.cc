#include <stdio.h>
#include <algorithm>
using namespace std;

const int dx[] = { 0,1 };
const int dy[] = { 1,0 };

int n, ans;
char a[55][55];

int check() {
	int ret = 1, cnt = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < n; j++) {
			if (a[i][j] == a[i][j + 1]) cnt++;
			else ret = max(ret, cnt), cnt = 1;
		}
		ret = max(ret, cnt), cnt = 1;
		for (int j = 1; j < n; j++) {
			if (a[j][i] == a[j + 1][i]) cnt++;
			else ret = max(ret, cnt), cnt = 1;
		}
		ret = max(ret, cnt), cnt = 1;
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", a[i] + 1);
	}

	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			for (int d = 0; d < 2; d++) {
				int nx = x + dx[d], ny = y + dy[d];
				if (!a[nx][ny]) continue;
				swap(a[x][y], a[nx][ny]);
				ans = max(ans, check());
				swap(a[x][y], a[nx][ny]);
			}
		}
	}

	printf("%d", ans);

	return 0;
}