#include <iostream>
using namespace std;
int n, m,k;
char mat[1005][1005],mattmp[1005][1005];
int sum[1005][1005][3];//0정글1바다2얼음
int main() {
	scanf("%d%d", &n, &m);
	scanf("%d", &k);
	for (int i = 0; i < n; i++)
		scanf("%s", mat[i]);
	mattmp[0][0] = ' ';
	for (int i = 0; i < n; i++) {
		mattmp[i+1][0] = ' ';
		for (int j = 0; j < m; j++) {
			mattmp[i + 1][j + 1] = mat[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int h = 0; h < 3; h++) {
				sum[i][j][h] += sum[i-1][j][h] + sum[i][j-1][h] - sum[i-1][j-1][h];
			}
			if (mattmp[i][j] == 'J') {
				sum[i][j][0] += 1;
			}
			else if (mattmp[i][j] == 'O') {
				sum[i][j][1] += 1;
			}
			else {
				sum[i][j][2] += 1;
			}
		}
	}
	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		for (int j = 0; j < 3; j++) {
			printf("%d ", sum[c][d][j] - sum[a - 1][d][j] - sum[c][b - 1][j] + sum[a - 1][b - 1][j]);
		}
		printf("\n");
	}
	return 0;
}