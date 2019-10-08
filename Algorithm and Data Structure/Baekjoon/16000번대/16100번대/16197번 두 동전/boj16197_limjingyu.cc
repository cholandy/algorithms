#include <iostream>
using namespace std;

struct point {
	int i, j;
};

int N, M, sol;
int map[22][22];
point coin1, coin2;
bool visited[22][22][22][22];

int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };

void dfs(int cnt) {
	bool out1 = false, out2 = false;
	if (coin1.i < 1 || coin1.i > N || coin1.j < 1 || coin1.j > M) out1 = true;
	if (coin2.i < 1 || coin2.i > N || coin2.j < 1 || coin2.j > M) out2 = true;

	if ((out1 && !out2) || (!out1 && out2)) {
		if (sol > cnt) sol = cnt;
		return;
	}
	if (cnt == 10 || sol <= cnt || (out1 && out2) || (coin1.i == coin2.i && coin1.j == coin2.j)) 
		return;

	point tmp1 = coin1, tmp2 = coin2;
	for (int k = 0; k < 4; k++) {
		if (map[coin1.i + di[k]][coin1.j + dj[k]] == 0) {
			coin1.i += di[k]; coin1.j += dj[k];
		}
		if (map[coin2.i + di[k]][coin2.j + dj[k]] == 0) {
			coin2.i += di[k]; coin2.j += dj[k];
		}
		if(!visited[coin1.i][coin1.j][coin2.i][coin2.j]) {
			visited[coin1.i][coin1.j][coin2.i][coin2.j] = true;
			dfs(cnt + 1);
			visited[coin1.i][coin1.j][coin2.i][coin2.j] = false;
		}
		coin1 = tmp1;
		coin2 = tmp2;
	}

	return;
}

int main() {
	cin >> N >> M;
	char ch;
	bool flag = true;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> ch;
			if (ch == 'o') {
				if (flag) {
					flag = false;
					coin1.i = i;
					coin1.j = j;
				}
				else {
					coin2.i = i;
					coin2.j = j;
				}
			}
			else if (ch == '.') {
				map[i][j] = 0;
			}
			else {
				map[i][j] = 1;
			}
		}
	}
	sol = 12;
	visited[coin1.i][coin1.j][coin2.i][coin2.j] = true;
	dfs(0);
	if (sol == 12) sol = -1;
	cout << sol << endl;
	return 0;
}