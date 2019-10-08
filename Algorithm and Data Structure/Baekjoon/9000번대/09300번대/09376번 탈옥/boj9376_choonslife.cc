#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
struct Po {
	int x, y, cnt;
};
int tc;
int n, m;
char mat[105][105];
int vi[3][105][105];
queue<Po> q[3];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
bool sf(int x, int y) {
	return (x >= 0 && y >= 0 && x < n + 2 && y < m + 2);
}
void bfs(int idx) {
	vi[idx][q[idx].front().x][q[idx].front().y] = 0;
	while (!q[idx].empty()) {
		int fx = q[idx].front().x;
		int fy = q[idx].front().y;
		int fcnt = q[idx].front().cnt;
		q[idx].pop();
		for (int mov = 0; mov < 4; mov++) {
			int mx = dx[mov] + fx, my = dy[mov] + fy;
			if (!sf(mx, my))continue;
			if (mat[mx][my] == '*')continue;
			if (mat[mx][my] == '#' && vi[idx][mx][my]>fcnt+1) {
				vi[idx][mx][my] = fcnt+1;
				q[idx].push({ mx,my,fcnt + 1 });
			}
			else if ((mat[mx][my] == '.'|| mat[mx][my]=='$') && vi[idx][mx][my]>fcnt ) {
				vi[idx][mx][my] = fcnt;
				q[idx].push({ mx,my,fcnt });
			}
		}
	}
}
int main() {
	scanf("%d", &tc);
	for (int testcase = 1; testcase <= tc; testcase++) {
		int ans = 0x3f3f3f3f;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) 
			scanf("%s", (mat[i] + 1));
		q[0].push({ 0,0,0 });
		for (int i = 0; i <= n + 1; i++) {
			for (int j = 0; j <= m + 1; j++) {
				vi[0][i][j]= vi[1][i][j]= vi[2][i][j] = 9999999;
				if (i == 0 || i == n + 1 || j == 0 || j == m + 1)
					mat[i][j] = '.';
				if (mat[i][j] == '$' && q[1].empty())
					q[1].push({ i,j,0 });
				else if (mat[i][j] == '$' && !q[1].empty())
					q[2].push({ i,j,0 });
			}
			mat[i][m + 2] = 0;
		}
		for (int i = 0; i < 3; i++) 
			bfs(i);

		for (int i = 0; i <= n + 1; i++) {
			for (int j = 0; j <= m + 1; j++) {
				if (mat[i][j] == '#') {
					ans = min(ans, vi[0][i][j] + vi[1][i][j] + vi[2][i][j] - 2);
				}
				else
					ans = min(ans, vi[0][i][j] + vi[1][i][j] + vi[2][i][j]);
			}
		}
		printf("%d\n", ans);
	}


	return 0;
}