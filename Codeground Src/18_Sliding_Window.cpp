#include <stdio.h>

#define MAX 5005

typedef int val_d;

val_d d[MAX];

int main() {

	int n, k;

	scanf("%d%d", &n, &k);

	for (int i = 0; i < n; i++)
		scanf("%d", &d[i]);

	val_d sum = 0, max = 0;

	for (int i = 0; i < n; i++) {
		if (i < k) sum += d[i];
		else sum = sum - d[i - k] + d[i];
		max = (max < sum) ? sum : max;
	}

	printf("%d\n", max);
}