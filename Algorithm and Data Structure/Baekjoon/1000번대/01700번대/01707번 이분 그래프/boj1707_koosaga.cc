#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

vector<int> graph[20005];

int col[20005];
int u[200005], v[200005];
int n, m;
bool vis[20005];

void dfs(int x){
	for(auto &i : graph[x]){
		if(vis[i]) continue;
		vis[i] = 1;
		col[i] = col[x] ^ 1;
		dfs(i);
	}
}
void solve(){
	scanf("%d %d",&n,&m);
	for(int i=0; i<=n; i++) graph[i].clear();
	memset(vis,0,sizeof(vis));
	for(int i=0; i<m; i++){
		scanf("%d %d",&u[i], &v[i]);
		graph[u[i]].push_back(v[i]);
		graph[v[i]].push_back(u[i]);
	}
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			vis[i] = 1;
			col[i] = 1;
			dfs(i);
		}
	}
	for(int i=0; i<m; i++){
		if(col[u[i]] + col[v[i]] != 1){
			puts("NO");
			return;
		}
	}
	puts("YES");
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
}