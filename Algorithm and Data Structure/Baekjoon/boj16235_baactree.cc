#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
int n, m, k;
pair<int, pair<int, int> > vec[100005], tvec[100005];
int vidx, tidx, pidx;
pair<int, int> p[100005];
int mat[10][10];
int arr[10][10];
int tmp[10][10];
int dx[8] = { -1,-1,-1,0,1,1,1,0 };
int dy[8] = { -1,0,1,1,1,0,-1,-1 };
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			mat[i][j] = 5;
		}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--; b--;
		vec[vidx++] = { c,{a,b} };
	}
	sort(vec, vec + vidx);
	while (k--) {
		tidx = pidx = 0;
		memset(tmp, 0, sizeof(tmp));
		for (int i = 0; i < vidx; i++) {
			int x = vec[i].second.first;
			int y = vec[i].second.second;
			int z = vec[i].first;
			if (mat[x][y] >= z) {
				mat[x][y] -= z;
				tvec[tidx++]={ z + 1,{x,y} };
				if ((z + 1) % 5 == 0) p[pidx++]={x,y};
			}
			else tmp[x][y] += z / 2;
		}
		vidx = 0;
		for (int i = 0; i < pidx; i++) {
			int x = p[i].first;
			int y = p[i].second;
			for (int j = 0; j < 8; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx>=0&&ny>=0&&nx<n&&ny<n) {
					vec[vidx++]={ 1,{nx,ny} };
				}
			}
		}
		for (int i = 0; i < tidx; i++)
			vec[vidx++] = tvec[i];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				mat[i][j] += arr[i][j] + tmp[i][j];
	}
	printf("%d\n", vidx);
	return 0;
}