#include <stdio.h>

#define MAX 105
#define INT_MAX 0x7fffffff

int n, d[MAX][MAX];

void floyd_warwhall() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (d[i][k] == INT_MAX || d[k][j] == INT_MAX) continue;

				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
			}
}

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			scanf("%d", &d[i][j]);
			if (d[i][j] == 0) d[i][j] = INT_MAX;
		}

	floyd_warwhall();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) printf("%d ", d[i][j]);
		printf("\n");
	}
}