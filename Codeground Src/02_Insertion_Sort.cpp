#include <stdio.h>

#define MAX 1000000

int d[MAX], n;

int main() {
    freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &d[i]);
	for (int i = 0; i < n; i++) {
		int temp = d[i];
		int j = i - 1;
		for (; j >= 0; j--) {
			if (d[j] < temp) break;
			d[j + 1] = d[j];
		}
		d[j + 1] = temp;
	}

	for (int i = 0; i < n; i++)
		printf("%d ", d[i]);

	return 0;
}
	