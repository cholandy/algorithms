#include <stdio.h>

#define TMAX (1 << 20)
#define MAX (1 << 19)

int tree[TMAX];
int v[MAX];
int n, m, s;

int min(int a, int b) {
	return (a > b) ? b : a;
}

void insert() {
	for (int i = s; i < s + n; i++)
		tree[i] = v[i - s];
	for (int i = s - 1; i >= 1; i--)
		tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
}

int getMin(int Left, int Right) {
	int l = Left + s - 1, r = Right + s - 1;
	int rval = 0x7fffffff;
	while (l <= r) {
		if (l % 2 == 0) l /= 2;
		else {
			rval = min(rval, tree[l]);
			l = (l / 2) + 1;
		}
		if (r % 2 == 1) r /= 2;
		else {
			rval = min(rval, tree[r]);
			r = (r / 2) - 1;
		}
	}
	return rval;
}


int main() {
	scanf("%d", &n);

	for (s = 1; s < n; s *= 2) {}
	for (int i = 1; i < s * 2; i++) tree[i] = 0x7fffffff;

	for (int i = 0; i < n; i++) scanf("%d", &v[i]);

	insert();

	scanf("%d", &m);

	while (m--) {
		int a, b; scanf("%d%d", &a, &b); 
		printf("%d\n", getMin(a, b));
	}
}