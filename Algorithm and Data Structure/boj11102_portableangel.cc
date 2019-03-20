#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int cap[200][200];
int flow[200][200];
int n, m; // 남, 여
int src, snc;

int maxflow() {
	int res=0;
	while(1) {
		int path[200];
		memset(path,-1,sizeof(path));
		queue<int> q;
		q.push(src);
		while(!q.empty() && path[snc]<0) {
			int u=q.front();
			q.pop();
			for(int v=0;v<n+m+2;v++) {
				if(path[v]<0 && cap[u][v]-flow[u][v]>0) {
					path[v]=u;
					q.push(v);
				}
			}
		}
		if(path[snc]<0) return res;
		for(int cur=snc;cur!=src;cur=path[cur]) {
			flow[path[cur]][cur]++;
			flow[cur][path[cur]]--;
		}
		res++;
	}
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		memset(cap,0,sizeof(cap));
		scanf("%d %d",&n,&m);
		src=n+m; snc=n+m+1;
		for(int u=0;u<m;u++) {
			int k;
			scanf("%d",&k);
			for(int i=0;i<k;i++) {
				int v;
				scanf("%d",&v);
				cap[v][u+n]=1;
			}
		}
		for(int i=0;i<n;i++)
			cap[src][i]=1;
		int res=1;
		while(1) {
			memset(flow,0,sizeof(flow));
			for(int i=n;i<n+m;i++)
				cap[i][snc]=res;
			if(maxflow()==n) break;
			res++;
			if(res==n+1) break;
		}
		if(res>n) puts("impossible");
		else printf("%d\n",res);
	}
}