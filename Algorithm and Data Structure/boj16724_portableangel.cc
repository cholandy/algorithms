#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> ip;

int dr[4] = { -1,0,1,0 }, dc[4] = { 0,1,0,-1 };
int n, m;
char b[1001][1001];
bool vis[1001][1001];

bool pos(int r, int c) {
	return 0 <= r&&r < n && 0 <= c&&c < m;
}

void bfs(int sr, int sc) {
	queue<ip> q;
	q.push(ip(sr, sc));
	vis[sr][sc] = true;
	while (!q.empty()) {
		int cr = q.front().first, cc = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = cr + dr[i], nc = cc + dc[i];
			if (!pos(nr, nc) || vis[nr][nc]) continue;
			bool ok = false;
			if (i == 0) {
				if (b[cr][cc] == 'U' || b[nr][nc] == 'D') ok = true;
			}
			else if (i == 1) {
				if (b[cr][cc] == 'R' || b[nr][nc] == 'L') ok = true;
			}
			else if (i == 2) {
				if (b[cr][cc] == 'D' || b[nr][nc] == 'U') ok = true;
			}
			else {
				if (b[cr][cc] == 'L' || b[nr][nc] == 'R') ok = true;
			}
			if (ok) {
				vis[nr][nc] = true;
				q.push(ip(nr, nc));
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", b[i]);
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j]) {
				res++;
				bfs(i, j);
			}
		}
	}
	printf("%d\n", res);
	return 0;
}