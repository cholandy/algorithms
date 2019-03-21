#include <cstdio>
#include <queue>

using namespace std;

int d[2002], v[2002];
queue<int> q;

void f(int x, int y) {
	if (d[x] > y) {
		d[x] = y;
		if (!v[x]) {
			v[x] = 1;
			q.push(x);
		}
	}
}

int main() {
	int i, j, n;
	scanf("%d", &n);
	for (i = 1; i <= 2000; i++) d[i] = 1e9;
	f(1, 0);
	while (!q.empty()) {
		v[i = q.front()] = 0;
		q.pop();
		for (j = 2; i * j <= 2000; j++) f(i * j, d[i] + j);
		for (j = 1; j < i; j++) f(i - j, d[i] + j);
	}
	printf("%d", d[n]);
	return 0;
}
