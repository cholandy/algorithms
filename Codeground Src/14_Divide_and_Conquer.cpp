#include <stdio.h>

#define MAX 5005

int d[MAX];
int temp[MAX];

void MergeSort(int L, int R) {
	if (L >= R) return;

	int M = (L + R) / 2;

	// Divide

	MergeSort(L, M);
	MergeSort(M + 1, R);

	// Conquer
	
	for (int i = L, l = L, r = M + 1;
		l != M + 1 || r != R + 1;
		i++) {

		if ((r != R + 1 && l <= M && d[l] < d[r]) || r == R + 1) {
			temp[i] = d[l++];
		} else {
			temp[i] = d[r++];
		}
	}

	for (int i = L; i <= R; i++) {
		d[i] = temp[i];
	}
}

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &d[i]);

	MergeSort(0, n - 1);

	for (int i = 0; i < n; i++)
		printf("%d ", d[i]);
}