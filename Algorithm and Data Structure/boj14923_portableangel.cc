#include <stdio.h>
#include <string.h>
#include <queue>
#include <tuple>

using namespace std;

typedef tuple<int,int,int> ti;

int a[1001][1001], n, m;
int d[2][1001][1001];
int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};

bool pos(int r, int c) {
	return 1<=r&&r<=n&&1<=c&&c<=m&&a[r][c]==0;
}

int main() {
	int hx, hy, ex, ey;
	scanf("%d %d %d %d %d %d",&n,&m,&hx,&hy,&ex,&ey);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	}
	if(!pos(hx,hy) || !pos(ex,ey)) {
		puts("-1");
		return 0;
	}
	queue<ti> q;
	q.push(ti(0,hx,hy));
	memset(d,-1,sizeof(d));
	d[0][hx][hy]=0;
	ti t;
	while(!q.empty()) {
		t=q.front();
		q.pop();
		int mm=get<0>(t), cr=get<1>(t), cc=get<2>(t);
		for(int i=0;i<4;i++) {
			int nr=cr+dr[i], nc=cc+dc[i];
			if(1<=nr && nr<=n && 1<=nc && nc<=m) {
				if(a[nr][nc]) {
					if(mm) continue;
					if(d[1][nr][nc]<0) {
						d[1][nr][nc]=d[mm][cr][cc]+1;
						q.push(ti(1,nr,nc));
					}
				} else {
					if(d[mm][nr][nc]<0) {
						d[mm][nr][nc]=d[mm][cr][cc]+1;
						q.push(ti(mm,nr,nc));
					}
				}
			}
		}
	}
	int res=d[0][ex][ey];
	if(res<0 || (d[1][ex][ey]>=0 && d[1][ex][ey]<res))
		res=d[1][ex][ey];
	printf("%d\n",res);
	return 0;
}