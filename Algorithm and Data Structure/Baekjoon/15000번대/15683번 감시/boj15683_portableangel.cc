#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int,int> ip;

int dr[4]={-1,0,1,0}, dc[4]={0,1,0,-1};
vector<ip> cc;
int b[8][8];
int n, m;
bool visit[8][8];

bool pos(int r, int c) {
	return 0<=r&&r<n&&0<=c&&c<m&&b[r][c]!=6;
}

int process(int key) {
	memset(visit,0,sizeof(visit));
	for(int i=0;i<cc.size();i++) {
		int t=b[cc[i].first][cc[i].second];
		vector<int> to;
		if(t==1) {
			to.push_back(key%4);
		} else if(t==2) {
			if(key%4==0 || key%4==2) {
				to.push_back(0); to.push_back(2);
			} else {
				to.push_back(1); to.push_back(3);
			}
		} else if(t==3) {
			to.push_back(key%4);
			to.push_back((key%4+1)%4);
		} else if(t==4) {
			for(int j=0;j<4;j++) if(j!=key%4)
				to.push_back(j);
		} else {
			for(int j=0;j<4;j++)
				to.push_back(j);
		}
		key>>=2;
		for(int j=0;j<to.size();j++) {
			int r1=cc[i].first, c1=cc[i].second, mv=1;
			for(;pos(r1+dr[to[j]]*mv,c1+dc[to[j]]*mv);mv++)
				visit[r1+dr[to[j]]*mv][c1+dc[to[j]]*mv]=true;
		}
	}
	int res=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++)
			if(!b[i][j] && !visit[i][j]) res++;
	}
	return res;
}

int main() {
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			scanf("%d",&b[i][j]);
			if(1<=b[i][j] && b[i][j]<=5) cc.push_back(ip(i,j));
		}
	}
	int res=(1<<30);
	for(int i=0;i<(1<<(2*cc.size()));i++)
		res=min(res,process(i));
	printf("%d\n",res);
	return 0;
}