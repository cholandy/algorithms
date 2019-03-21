#include <cstdio>
#include <vector>
using namespace std;

bool ret = true;
bool colp[100005], vis[100005];
int par[100005];
vector<int> graph[100005];

void dfs(int x, int pa){
	vis[x] = 1;
	par[x] = pa;
	for(auto &i : graph[x]){
		if(i == pa) continue;
		if(!vis[i]) continue;
		int pos = x;
		while(1){		
			if(colp[pos]){
				ret = 0;
				break;		
			}
			colp[pos] = 1;
			if(pos == i) break;
			pos = par[pos];
		}
	}
	for(auto &i : graph[x]){
		if(i == pa) continue;
		if(vis[i]) continue;
		dfs(i, x);
	}
}

int main(){
	int n, m;
	scanf("%d %d",&n,&m);
	for(int i=0; i<m; i++){
		int u, v;
		scanf("%d %d",&u,&v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(1, 0);
	puts(ret ? "Cactus" : "Not cactus");
}