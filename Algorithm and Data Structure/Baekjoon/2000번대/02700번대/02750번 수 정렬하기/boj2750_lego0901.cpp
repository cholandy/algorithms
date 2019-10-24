#include <stdio.h>
#include <algorithm>

int main() {
	int n, i;
	int nums[1001];
	scanf ( "%d", &n );
	for (i = 0; i < n; i++)
		scanf ( "%d", nums + i );
	std::sort(nums, nums + i);
	for (i = 0; i < n; i++)
		printf ( "%d\n", nums[i] );
}