#include <stdio.h>

#define MAX 5005

int A[MAX], B[MAX];
int Sorted[MAX + MAX];

int main() {
	int n, m;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);

	scanf("%d", &m);

	for(int i = 0 ; i < m ; i++)
		scanf("%d", &B[i]);

	int a = 0, b = 0;

	for (int i = 0; i < n + m; i++) {
		if (b == m || (b != m && a < n && A[a] < B[b]))
			Sorted[i] = A[a++];
		else
			Sorted[i] = B[b++];
	}

	for (int i = 0; i < n + m; i++)
		printf("%d ", Sorted[i]);
}