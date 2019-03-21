#include <stdio.h>
#include <string.h>
#include <queue>
#include <utility>

using namespace std;

int cost[20][20], n;

int bfs(int s, int e) {
	queue<int> q;
	q.push(s);
	int d[21];
	memset(d,-1,sizeof(d));
	d[s]=0;
	int temp=cost[s][e];
	cost[s][e]=0;
	while(!q.empty()) {
		int cur=q.front();
		q.pop();
		for(int v=0;v<n;v++) if(cost[cur][v]) {
			if(d[v]<0 || d[v]>d[cur]+cost[cur][v]) {
				d[v]=d[cur]+cost[cur][v];
				q.push(v);
			}}
	}
	cost[s][e]=temp;
	if(d[e]<0) return cost[s][e];
	else if(d[e]==cost[s][e]) return 0;
	else if(d[e]<cost[s][e]) return -1;
	else return cost[s][e];
}

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			scanf("%d",&cost[i][j]);
		}}

	for(int i=0;i<n;i++) {
		if(cost[i][i]) {
			printf("-1");
			return 0;
		}
		for(int j=0;j<n;j++) {
			if(cost[i][j]!=cost[j][i]) {
				printf("-1");
				return 0;
			}}
	}

	int res=0;
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			int r=bfs(i,j);
			if(r<0) {
				printf("-1");
				return 0;
			}
			res+=r;
		}}

	printf("%d",res);
}