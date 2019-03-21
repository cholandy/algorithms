#include <stdio.h>

char s[4][9];
int k;

int main() {
	for(int i=0;i<4;i++)
		scanf("%s",s[i]);
	scanf("%d",&k);
	while(k--) {
		int p, d, dir[4]={0};
		scanf("%d %d",&p,&d); --p;
		dir[p]=d;
		for(int i=p-1;i>=0;i--) {
			if(s[i][2]!=s[i+1][6]) dir[i]=-dir[i+1];
			else break;
		}
		for(int i=p+1;i<4;i++) {
			if(s[i-1][2]!=s[i][6]) dir[i]=-dir[i-1];
			else break;
		}
		for(int i=0;i<4;i++) {
			if(dir[i]==-1) {
				char t=s[i][0];
				for(int j=0;j<7;j++)
					s[i][j]=s[i][j+1];
				s[i][7]=t;
			} else if(dir[i]==1) {
				char t=s[i][7];
				for(int j=7;j>0;j--)
					s[i][j]=s[i][j-1];
				s[i][0]=t;
			}
		}
	}
	int res=0;
	for(int i=0;i<4;i++) {
		if(s[i][0]=='1') res+=(1<<i);
	}
	printf("%d\n",res);
	return 0;
}