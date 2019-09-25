#include <stdio.h>

int main() {
	int d[100001]={0}, n, k, w, v;
	scanf("%d %d",&n,&k);
	while(n--) {
		scanf("%d %d",&w,&v);
		for(int i=k;i>=w;i--) {
			if(d[i-w]+v>d[i]) d[i]=d[i-w]+v;
		}
	}
	printf("%d\n",d[k]);
	return 0;
}