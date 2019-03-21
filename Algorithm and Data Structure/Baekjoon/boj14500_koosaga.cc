#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m, a[505][505];
int chk[505][505];
pi v[4];

int solve(int dep){
	if(dep == 4) return 0;
	int ret = 0;
	for(int ii=0; ii<dep; ii++){
		auto i = v[ii];
		for(int j=0; j<4; j++){
			if(i.first + dx[j] < 0 || i.first + dx[j] >= n ||
					i.second + dy[j] < 0 || i.second + dy[j] >= m){
				continue;
			}
			if(chk[i.first + dx[j]][i.second + dy[j]]) continue;
			chk[i.first + dx[j]][i.second + dy[j]] = 1;
			v[dep] = pi(i.first + dx[j], i.second + dy[j]);
			ret = max(ret, a[i.first + dx[j]][i.second + dy[j]]
					+ solve(dep+1));
			chk[i.first + dx[j]][i.second + dy[j]] = 0;
		}
	}
	return ret;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d",&a[i][j]);
		}
	}
	int ret = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			v[0] = pi(i, j);
			chk[i][j] = 1;
			ret = max(ret, solve(1) + a[i][j]);
			chk[i][j] = 0;
		}
	}
	cout << ret;
}
