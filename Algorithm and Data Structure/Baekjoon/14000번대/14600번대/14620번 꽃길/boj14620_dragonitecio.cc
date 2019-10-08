#include <iostream>

#include <algorithm>

using namespace std;

#define SIZE 12 // 12



int x, y, nx, ny;

int map[SIZE][SIZE];

int visit[SIZE][SIZE];

int sum;

int N;

int minVal = 2123456789;



void problemIn() {

	cin >> N;

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			cin >> map[i][j];

		}

	}

}



// 맵 안에 들어오는지, 다른 꽃은 없는지 체크해서 괜찮으면 1 출력, 안 괜찮으면 0 출력

int check(int x, int y) {

	if (x + 1 < N && x - 1 >= 0 && y - 1 >= 0 && y + 1 < N) {

		if (visit[x][y] == 0 && visit[x+1][y] == 0 && visit[x-1][y] == 0 && visit[x][y+1] == 0 && visit[x][y-1] == 0) {

			return 1;

		}

	}

	return 0;

}







void dfs(int depth, int x, int y, int sum) {



	if (depth == 3) {

		minVal = min(minVal, sum);

		return;

	}

	

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			if (check(i, j)) {

				visit[i][j] = visit[i + 1][j] = visit[i - 1][j] = visit[i][j + 1] = visit[i][j - 1] = 1;

				sum = sum + map[i][j] + map[i + 1][j] + map[i - 1][j] + map[i][j + 1] + map[i][j - 1];

				dfs(depth + 1, i, j, sum);

				visit[i][j] = visit[i + 1][j] = visit[i - 1][j] = visit[i][j + 1] = visit[i][j - 1] = 0;

				sum = sum - map[i][j] - map[i + 1][j] - map[i - 1][j] - map[i][j + 1] - map[i][j - 1];

			}

		}

	}

}



void solve() {

	dfs(0, 0, 0, 0);

}



int main() {

	problemIn();

	solve();

	cout << minVal << endl;

	return 0;

} 



