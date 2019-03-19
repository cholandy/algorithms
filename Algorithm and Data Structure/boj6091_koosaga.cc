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
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

struct edg{int s, e, x;};
vector<edg> v;

struct disj{
	int pa[1025];
	void init(int n){
		for(int i=0; i<=n; i++) pa[i] = i;
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p); q = find(q);
		if(p == q) return 0;
		pa[q] = p; return 1;
	}
}disj;

vector<int> graph[1025];

int main(){
	int n;
	scanf("%d",&n);
	disj.init(n);
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			int x;
			scanf("%d",&x);
			v.push_back({i, j, x});
		}
	}
	sort(v.begin(), v.end(), [&](const edg &a, const edg &b){
		return a.x < b.x;
	});
	for(auto &i : v){
		if(disj.uni(i.s, i.e)){
			graph[i.s].push_back(i.e);
			graph[i.e].push_back(i.s);
		}
	}
	for(int i=1; i<=n; i++){
		sort(graph[i].begin(), graph[i].end());
		printf("%d ",graph[i].size());
		for(auto &j : graph[i]){
			printf("%d ",j);
		}
		puts("");
	}
}