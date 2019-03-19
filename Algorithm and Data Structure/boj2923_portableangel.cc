#include <stdio.h>
#include <algorithm>

using namespace std;

int cnt[101][2], c[101][2];

int process() {
	for(int i=1;i<=100;i++) {
		c[i][0]=cnt[i][0];
		c[i][1]=cnt[i][1];
	}
	int res=0;
	int i=1, j=100;
	while(c[i][0]==0) i++;
	while(c[j][1]==0) j--;
	while(i<=100 || j>=1) {
		while(c[i][0]==0 && i<=100) i++;
		while(c[j][1]==0 && j>0) j--;
		if(i>100 || j<1) break;
		if(c[i][0]>=c[j][1]) {
			res=max(res,i+j);
			c[i][0]-=c[j][1];
			j--;
		} else {
			res=max(res,i+j);
			c[j][1]-=c[i][0];
			i++;
		}
	}
	return res;
}

int main() {
	int n;
	scanf("%d",&n);
	while(n--) {
		int a, b;
		scanf("%d %d",&a,&b);
		cnt[a][0]++; cnt[b][1]++;
		printf("%d\n",process());
	}
	return 0;
}