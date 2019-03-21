#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define INF 1234567

int a[10][10];
char buf[11];
int dr[5]={-1,0,1,0,0};
int dc[5]={0,1,0,-1,0};

bool pos(int r, int c) {
	return 0<=r&&r<10&&0<=c&&c<10;
}

int b[10][10];

int process(int h) {
	for(int i=0;i<10;i++) {
		for(int j=0;j<10;j++)
			b[i][j]=a[i][j];
	}
	int res=0;
	for(int i=0;i<10;i++) {
		int cr=0, cc=i;
		if(h&(1<<i)) {
			for(int j=0;j<5;j++) {
				int nr=cr+dr[j], nc=cc+dc[j];
				if(pos(nr,nc)) b[nr][nc]^=1;
			}
			res++;
		}
	}
	for(int i=1;i<10;i++) {
		for(int j=0;j<10;j++) {
			if(b[i-1][j]) {
				res++;
				for(int k=0;k<5;k++) {
					int nr=i+dr[k], nc=j+dc[k];
					if(pos(nr,nc)) b[nr][nc]^=1;
				}
			}
		}
	}
	for(int j=0;j<10;j++) {
		if(b[9][j]) return INF;
	}
	return res;
}

int main() {
	for(int i=0;i<10;i++) {
		scanf("%s",buf);
		for(int j=0;j<10;j++) {
			if(buf[j]=='O') a[i][j]=1;
		}
	}
	int res=INF;
	for(int i=0;i<(1<<10);i++)
		res=min(res,process(i));
	if(res==INF) res=-1;
	printf("%d\n",res);
	return 0;
}