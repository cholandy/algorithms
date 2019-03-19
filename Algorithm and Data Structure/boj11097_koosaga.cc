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
 
int n;
bool adj[305][305], nadj[305][305];
int comp[305];
vector<int> grp[305];

void dfs(int x, int p){
	if(comp[x]) return;
	grp[p].push_back(x);
	comp[x] = p;
	for(int i=1; i<=n; i++){
		if(adj[x][i] && adj[i][x]) dfs(i, p);
	}
}
 
int main(){
	int t;
	cin >> t;
	while(t--){
		for(int i=0; i<305; i++) grp[i].clear();
		memset(comp, 0, sizeof(comp));
		memset(adj, 0, sizeof(adj));
		memset(nadj, 0, sizeof(nadj));
		scanf("%d",&n);
		char buf[305];
		for(int j=1; j<=n; j++){
			scanf("%s", buf + 1);
			for(int k=1; k<=n; k++){
				adj[j][k] = (buf[k] == '1');
			}
		}
		int p = 0;
		for(int i=1; i<=n; i++){
			if(!comp[i]){
				dfs(i, ++p);
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(adj[i][j] && comp[i] != comp[j]){
					nadj[comp[i]][comp[j]] = 1;
				}
			}
		}
		vector<pi> ret;
		for(int i=1; i<=p; i++){
			for(int j=1; j<=p; j++){
				if(!nadj[i][j]) continue;
				int ok = 1;
				for(int k=1; k<=p; k++){
					if(i == k || j == k) continue;
					if(nadj[i][k] && nadj[k][j]) ok = 0;
				}
				if(ok) ret.push_back(pi(grp[i][0], grp[j][0]));
			}
		}
		for(int i=1; i<=p; i++){
			for(int j=0; j<grp[i].size(); j++){
				int l = grp[i][j];
				int r = grp[i][(j+1)%grp[i].size()];
				if(l != r) ret.push_back(pi(l, r));
			}
		}
		printf("%d\n",ret.size());
		for(auto &i : ret){
			printf("%d %d\n",i.first, i.second);
		}
		puts("");
	}
}