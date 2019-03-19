#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

struct edg{
	int pos, cap, rev;
};

vector<edg> graph[2005];

void add_edge(int s, int e, int x){
	graph[s].push_back({e, x, (int)graph[e].size()});
	graph[e].push_back({s, 0, (int)graph[s].size()-1});
}

bool vis[2005];
int pa[2005], pe[2005];

bool dfs(int x, int d){
	if(x == d) return 1;
	if(vis[x]) return 0;
	vis[x] = 1;
	int p=0;
	for(auto &i : graph[x]){
		if(i.cap > 0 && dfs(i.pos, d)){
			pa[i.pos] = x;
			pe[i.pos] = p;
			return 1;
		}
		p++;
	}
	return 0;
}

int match(int d){
	int ret = 0;
	memset(vis,0,sizeof(vis));
	while(dfs(0, d)){
		memset(vis,0,sizeof(vis));
		int pos = d;
		while(pos){
			int rev = graph[pa[pos]][pe[pos]].rev;
			graph[pa[pos]][pe[pos]].cap--;
			graph[pos][rev].cap++;
			pos = pa[pos];
		}
		ret++;
	}
	return ret;
}

int n, m, k;

int main(){
	scanf("%d %d %d",&n,&m,&k);
	add_edge(0, n+m+2, k);
	for(int i=1; i<=n; i++){
		add_edge(n+m+2, i, 1);
		add_edge(0, i, 1);
		int q;
		scanf("%d",&q);
		while(q--){
			int x;
			scanf("%d",&x);
			add_edge(i, x+n, 1);
		}
	}
	for(int i=1; i<=m; i++) add_edge(n+i,n+m+1,1);
	printf("%d", match(n+m+1));
}