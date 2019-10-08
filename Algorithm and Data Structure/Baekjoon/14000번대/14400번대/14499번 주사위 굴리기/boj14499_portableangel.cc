#include <stdio.h>

int p[4][6]={{3,0,2,5,4,1}, {4,1,0,3,5,2}, {1,5,2,0,4,3}, {2,1,5,3,0,4}};
int a[20][20], n, m, cr, cc, k;
int to[5]={0,0,2,3,1};
int dr[4]={0,1,0,-1};
int dc[4]={1,0,-1,0};

bool pos(int r, int c) {
	return 0<=r&&r<n&&0<=c&&c<m;
}

int b[6];

void rot(int dir) {
	int t[6];
	for(int i=0;i<6;i++)
		t[p[dir][i]]=b[i];
	for(int i=0;i<6;i++)
	b[i]=t[i];
}

int main() {
	scanf("%d %d %d %d %d",&n,&m,&cr,&cc,&k);
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	}
	while(k--) {
		int dir;
		scanf("%d",&dir);
		dir=to[dir];
		if(!pos(cr+dr[dir],cc+dc[dir])) continue;
		cr+=dr[dir]; cc+=dc[dir];
		rot(dir);
		printf("%d\n",b[0]);
		if(a[cr][cc]) { b[5]=a[cr][cc]; a[cr][cc]=0; }
		else a[cr][cc]=b[5];
	}
	return 0;
}