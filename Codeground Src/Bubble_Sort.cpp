#include <stdio.h>

#define MAX 5005

int d[MAX];

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int main()
{
    freopen("input.txt", "r", stdin);
	int n; 
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i++)
		scanf("%d", &d[i]);
	for(int i = 0 ; i < n - 1 ; i++) {
		for(int j = 0; j < n - i - 1; j++) {
			if(d[j] > d[j + 1]) {
				swap(&d[j], &d[j + 1]);
			}
		}
	}

	for(int i = 0 ; i < n ; i++)
		printf("%d\n", d[i]);

	return 0;
}