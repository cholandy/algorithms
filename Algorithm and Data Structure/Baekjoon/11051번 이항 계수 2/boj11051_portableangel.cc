#include <stdio.h>
#include <string.h>

#define MOD 10007

int d[1001][1001];

int f(int n, int r) {
	if(r==0 || n==r) return 1;
	if(d[n][r]>=0) return d[n][r];
	return d[n][r]=(f(n-1,r-1)+f(n-1,r))%MOD;
}

int main() {
	int n, r;
	memset(d,-1,sizeof(d));
	scanf("%d %d",&n,&r);
	printf("%d",f(n,r));
}