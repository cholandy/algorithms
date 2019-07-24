#include <stdio.h>
// #include <stdbool.h>

#define MAX 10000001

int d[MAX], n;

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

bool bsearch(int val) {
	int l = 0, r = n - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (val == d[mid]) return true;
		else if (val > d[mid]) l = mid + 1;
		else r = mid - 1;
	}

	return false;
}

int main() {
	freopen("output.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &d[i]);

	// // sorting
	// for (int i = 0; i < n; i++)
	// 	for (int j = i + 1; j < n; j++)
	// 		if (d[i] > d[j]) 
	// 			swap(&d[i], &d[j]);
			

	int query; scanf("%d", &query);

	while (query--) {
		int x; scanf("%d", &x);
		if (bsearch(x)) printf("exist\n");
		else printf("not exist\n");
	}
}