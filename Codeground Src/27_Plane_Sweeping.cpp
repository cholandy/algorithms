#include <stdio.h>

#define MAX 5005

struct rect {
	int x, y, height, width;
}d[MAX];

int x[MAX], y[MAX];
int temp[MAX];

int xc, yc;

void MergeSort(int L, int R, int d[]) {
	if (L >= R) return;

	int M = (L + R) / 2;

	MergeSort(L, M, d);
	MergeSort(M + 1, R, d);

	for (int i = L, l = L, r = M + 1;
		l != M + 1 || r != R + 1;
		i++) {

		if ( (r != R + 1 && l <= M && d[l] < d[r]) || r == R + 1)
			temp[i] = d[l++];

		else
			temp[i] = d[r++];
	}

	for (int i = L; i <= R; i++)
		d[i] = temp[i];
}

int main() 
{
	int n; scanf("%d", &n);

	int ans = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &d[i].x, &d[i].y, &d[i].width, &d[i].height);
		x[xc++] = d[i].x;
		x[xc++] = d[i].x + d[i].width;
		y[yc++] = d[i].y;
		y[yc++] = d[i].y + d[i].height;
	}

	MergeSort(0, xc - 1, x);
	MergeSort(0, yc - 1, y);

	for (int i = 0; i < xc - 1; i++)
		for (int j = 0; j < yc - 1; j++)
			for (int k = 0; k < n; k++)
				if (x[i] >= d[k].x && x[i + 1] <= d[k].x + d[k].width &&
					y[j] >= d[k].y && y[j + 1] <= d[k].y + d[k].height) {
					ans += (x[i + 1] - x[i]) * (y[j + 1] - y[j]);
					break;
				}

	printf("%d", ans);
}