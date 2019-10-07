#include <stdio.h>
#define SIZE 1000005
typedef long long ll;
int n, m, k;
ll arr[SIZE];
ll tree[SIZE * 4];
int tree_size;
void init() {
	tree_size = 1;
	while (tree_size < n)
		tree_size <<= 1;
	for (int i = 0; i < n; i++) {
		int tmp = tree_size + i;
		while (tmp) {
			tree[tmp] += arr[i];
			tmp >>= 1;
		}
	}
}
void update(int idx, ll val) {
	idx = tree_size + idx;
	while (idx) {
		tree[idx] += val;
		idx >>= 1;
	}
}
ll sum_(int idx1, int idx2) {
	ll ret = 0ll;
	idx1 = tree_size  + idx1;
	idx2 = tree_size  + idx2;
	while (idx1 <= idx2) {
		if (idx1 & 1)
			ret += tree[idx1++];
		if (!(idx2 & 1))
			ret += tree[idx2--];
		idx1 >>= 1;
		idx2 >>= 1;
	}
	return ret;
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)scanf("%lld", &arr[i]);
	init();
	for (int i = 0; i < m + k; i++) {
		int a, b;
		ll c;
		scanf("%d%d%lld", &a, &b, &c);
		if (a == 1) {
			update(b - 1, c-arr[b-1]);
			arr[b - 1] = c;
		}
		if (a == 2) {
			printf("%lld\n", sum_(b - 1, c - 1));
		}
	}
	return 0;
}