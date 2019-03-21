#include <stdio.h>
struct data {
	long long max, min, maxchk, minchk;
} index_tree[3000000];
long long max(long long a, long long b) {
	if(a<b) return b;
	else return a;
}
long long min(long long a, long long b) {
	return -max(-a, -b);
}
void input(int a, long long b) {
	index_tree[a].max = index_tree[a].min = b;
	index_tree[a].maxchk = index_tree[a].minchk = a;
	while(a > 1) {
		a /= 2;
		index_tree[a].max = max(index_tree[2*a].max, index_tree[2*a+1].max);
		index_tree[a].min = min(index_tree[2*a].min, index_tree[2*a+1].min);
		if(index_tree[2*a].max > index_tree[2*a+1].max) index_tree[a].maxchk = index_tree[2*a].maxchk;
		else index_tree[a].maxchk = index_tree[2*a+1].maxchk;
		if(index_tree[2*a].min < index_tree[2*a+1].min) index_tree[a].minchk = index_tree[2*a].minchk;
		else index_tree[a].minchk = index_tree[2*a+1].minchk;
	}
	return;
}
void remove(long long a) {
	index_tree[a].max = (long long) 3000000000 * -1;
	index_tree[a].min = (long long) 3000000000;
	index_tree[a].maxchk = index_tree[a].minchk = 0;
	while(a > 1) {
		a /= 2;
		index_tree[a].max = max(index_tree[2*a].max, index_tree[2*a+1].max);
		index_tree[a].min = min(index_tree[2*a].min, index_tree[2*a+1].min);
		if(index_tree[2*a].max > index_tree[2*a+1].max) index_tree[a].maxchk = index_tree[2*a].maxchk;
		else index_tree[a].maxchk = index_tree[2*a+1].maxchk;
		if(index_tree[2*a].min < index_tree[2*a+1].min) index_tree[a].minchk = index_tree[2*a].minchk;
		else index_tree[a].minchk = index_tree[2*a+1].minchk;
	}
	return;
}
int main() {
	int T, N, M, i, cnt;
	long long t;
	char chk;
	scanf("%d", &T);
	for(int test_no = 1; test_no <= T; test_no++) {
		N = 0, cnt = 0;
		for(i = 0; i <= 2097152; i++) {
			index_tree[i].max = (long long) 3000000000 * -1;
			index_tree[i].min = (long long) 3000000000;
			index_tree[i].maxchk = 0;
			index_tree[i].minchk = 0;
		}
		scanf("%d", &M);
		for(i = 1; i <= M; i++) {
			scanf("\n%c %lld", &chk, &t);
			if(chk == 'I') {
				input(N+1048576, t);
				N++;
				cnt++;
				continue;
			}
			if(cnt == 0) continue;
			cnt--;
			if(t == -1) t = index_tree[1].minchk;
			else t = index_tree[1].maxchk;
			remove(t);
		}
		if(cnt == 0) printf("EMPTY\n");
		else printf("%lld %lld\n", index_tree[1].max, index_tree[1].min);
	}
	return 0;
}