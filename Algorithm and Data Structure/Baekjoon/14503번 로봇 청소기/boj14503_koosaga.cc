#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int n, m, x, y, d;
int a[51][51];

bool ok (int x, int y){
	return x >= 0 && x<n && y >=0 && y <m && !a[x][y];
}
 int wall[51][51];

int main(){
	cin >> n >> m;
	cin >> x >> y >> d;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> a[i][j];
			wall[i][j] = a[i][j];
		}
	}
	while(1){
		a[x][y] = 1;
		bool fnd = 0;
		for(int i=d+3; i>=d; i--){
			int nxt = i % 4;
			if(ok(x + dx[nxt], y + dy[nxt])){
				x += dx[nxt];
				y += dy[nxt];
				d = nxt;
				fnd = 1;
				break;
			}
		}
		if(fnd) continue;
		int nxt = d;
		if(!wall[x - dx[nxt]][y - dy[nxt]]){
			x -= dx[nxt];
			y -= dy[nxt];
		}
		else break;
	}
	int ans = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(!wall[i][j] && a[i][j]) ans++;
		}
	}
	cout << ans;
}
