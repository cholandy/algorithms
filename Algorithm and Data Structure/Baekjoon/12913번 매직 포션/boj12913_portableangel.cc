#include <stdio.h>
#include <queue>
#include <vector>
#include <functional>
#include <tuple>
#include <string.h>
#include <algorithm>

using namespace std;

typedef tuple<int, int, int> ti;

int n, k, a[50][50], d[50][51];
bool fix[50][51];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &a[i][j]);
			a[i][j] <<= 1;
		}
	}
	priority_queue<ti,vector<ti>,greater<ti> > q;
	memset(d, -1, sizeof(d));
	d[0][k] = 0;
	q.push(ti(0, 0, k));
	ti t;
	while (!q.empty()) {
		int dis, u, rem;
		do {
			t = q.top(); q.pop();
			dis = get<0>(t), u = get<1>(t), rem = get<2>(t);
		} while (!q.empty() && fix[u][rem]);
		if (fix[u][rem]) break;
		fix[u][rem] = true;
		for (int i = 0; i < n; i++) {
			if (d[i][rem]<0 || d[i][rem]>dis + a[u][i]) {
				d[i][rem] = dis + a[u][i];
				q.push(ti(d[i][rem], i, rem));
			}
			if (rem && (d[i][rem - 1]<0 || d[i][rem - 1]>dis + a[u][i] / 2)) {
				d[i][rem - 1] = dis + a[u][i] / 2;
				q.push(ti(d[i][rem - 1], i, rem - 1));
			}
		}
	}
	int res = (1 << 30);
	for (int i = 0; i <= k; i++) if(d[1][i]>=0) {
		res = min(res, d[1][i]);
	}
	printf("%.1f\n", res / 2.0);
	return 0;
}